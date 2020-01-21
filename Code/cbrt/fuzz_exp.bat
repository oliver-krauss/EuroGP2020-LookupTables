#WBL 22 May 2018 test GI version of cbrt based on fuzz1.bat r1.1 

setenv seed 104103
if( $1 != "" ) setenv seed $1

echo $0 '$Revision: 1.1 $' $seed $HOST `pwd` `date`

set id=0
while ( $id < 5120 )
  set num= ( `gawk -v "id=$id" -v "seed=$id$seed" 'END{	\
		srand(seed);	\
		sign     = (id%2)? "-" : "";	\
		expsign  = ((id/2)%2)? "-" : "+";	\
		fraction = 1+rand();	\
		exponent = int(rand()*308);	\
		printf("%s%fe%s%d\n",sign,fraction,expsign,exponent);	\
		}' /dev/null` )
  main2 $num;
  setenv save $status;
  if( $save ) then
    echo "main2 $id failed $save " `date`
    #exit $save;
  endif
  set id=(`expr $id + 1`)
end

#
