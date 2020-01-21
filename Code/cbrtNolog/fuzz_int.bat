#WBL 22 May 2018 test GI version of cbrt based on fuzz_exp.bat r1.1 

setenv seed 105953 
if( $1 != "" ) setenv seed $1

echo $0 '$Revision: 1.1 $' $seed $HOST `pwd` `date`

set id=0
while ( $id < 5120 )
  set num= ( `gawk -v "id=$id" -v "seed=$id$seed" 'END{	\
		srand(seed);	\
		printf("0x");	\
		for(i=0;i<8;i++) {	\
		  printf("%02x",int(rand()*256));	\
		  if(i==3) printf(",");}	\
		printf("\n");	\
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
