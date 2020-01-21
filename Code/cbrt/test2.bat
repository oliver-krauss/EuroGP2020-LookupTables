#!/bin/csh
#WBL 21 May 2018 test GI version of cbrt based on test.bat r1.8

setenv seed 153504
if( $1 != "" ) setenv seed $1

echo $0 '$Revision: 1.2 $' $seed $HOST `pwd` `date`

./main2 `gawk 'END{print 0x1fffffffffffff}' /dev/null`
./main2 `gawk 'END{print 0x1ff8ffffffffff}' /dev/null`
./main2 `gawk 'END{print 0x1ff80000000000}' /dev/null`
./main2 `gawk 'END{print 0x1ff00000000000}' /dev/null`


set id=0
while ( $id <= 768 )
  set num= ( `gawk -v "id=$id" 'END{print 0x10000000000000 + 0x100000000000*id}' /dev/null` )
  gawk -v "id=$id" -v "num=$num" 'END{printf("%4d %x\n",id,num)}' /dev/null
  ./main2 $num;
  setenv save $status;
  if( $save ) then
    echo "main2 $id failed $save " `date`
    #exit $save;
  endif

  set num= ( `gawk -v "id=$id" 'END{d=(id<=255)? 0x0fffffffffff:0x01ffffffffffe;print 0x10000000000000 + 0x100000000000*id + d  }' /dev/null` )
  gawk -v "id=$id" -v "num=$num" 'END{printf("%4d %x\n",id,num)}' /dev/null
  ./main2 $num;
  setenv save $status;
  if( $save ) then
    echo "main2 $id failed $save " `date`
    #exit $save;
  endif

  set num= ( `gawk -v "id=$id" -v "seed=$id$seed" 'END{srand(seed);d=(id<=255)? 0x0fffffffffff*rand():0x01ffffffffffe*rand();print 0x10000000000000 + 0x100000000000*id + d  }' /dev/null` )
  gawk -v "id=$id" -v "num=$num" 'END{printf("%4d %x\n",id,num)}' /dev/null
  ./main2 $num;
  setenv save $status;
  if( $save ) then
    echo "main2 $id failed $save " `date`
    #exit $save;
  endif

  if( $id <= 255 ) then
    set id=(`expr $id + 1`)
  else
    set id=(`expr $id + 2`)
  endif
end


#
