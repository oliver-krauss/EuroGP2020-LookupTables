#WBL 22 May 2018 test GI version of cbrt based on test.bat r1.8 

#WBL 10 Jun 2018 for log2

setenv seed 094944
if( $1 != "" ) setenv seed $1

echo $0 '$Revision: 1.2 $' $seed $HOST `pwd` `date`

set id=0
while ( $id < 5120 )
  set num= ( `gawk -v "id=$id" -v "seed=$id$seed" 'END{srand(seed);d=(id%2)? -(1+rand()):(1+rand());print d  }' /dev/null` )
  main2 $num;
  setenv save $status;
  if( $save ) then
    echo "main2 $id failed $save " `date`
    #exit $save;
  endif
  set id=(`expr $id + 1`)
end


#
