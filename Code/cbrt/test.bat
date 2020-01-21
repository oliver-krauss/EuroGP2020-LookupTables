#WBL 18 May 2018 from gi_glibc/glibc-2.27_config_make.script

setenv seed 153504
if( $1 != "" ) setenv seed $1

echo $0 '$Revision: 1.8 $' $seed $HOST `pwd` `date`

#main 0x1fffffffffffff
#main 0x1ff8ffffffffff
#main 0x1ff80000000000
#main 0x1ff00000000000


set id=0
while ( $id <= 768 )
  set num= ( `gawk -v "id=$id" 'END{print 0x10000000000000 + 0x100000000000*id}' /dev/null` )
  gawk -v "id=$id" -v "num=$num" 'END{printf("%4d %x\n",id,num)}' /dev/null
  ./main $num;
  setenv save $status;
  if( $save ) then
    echo "main $id failed $save " `date`
    exit $save;
  endif

  set num= ( `gawk -v "id=$id" 'END{d=(id<=255)? 0x0fffffffffff:0x01ffffffffffe;print 0x10000000000000 + 0x100000000000*id + d  }' /dev/null` )
  gawk -v "id=$id" -v "num=$num" 'END{printf("%4d %x\n",id,num)}' /dev/null
  ./main $num;
  setenv save $status;
  if( $save ) then
    echo "main $id failed $save " `date`
    exit $save;
  endif

  set num= ( `gawk -v "id=$id" -v "seed=$id$seed" 'END{srand(seed);d=(id<=255)? 0x0fffffffffff*rand():0x01ffffffffffe*rand();print 0x10000000000000 + 0x100000000000*id + d  }' /dev/null` )
  gawk -v "id=$id" -v "num=$num" 'END{printf("%4d %x\n",id,num)}' /dev/null
  ./main $num;
  setenv save $status;
  if( $save ) then
    echo "main $id failed $save " `date`
    exit $save;
  endif

  if( $id <= 255 ) then
    set id=(`expr $id + 1`)
  else
    set id=(`expr $id + 2`)
  endif
end


#
