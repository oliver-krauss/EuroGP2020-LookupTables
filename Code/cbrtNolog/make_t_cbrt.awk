#WBL 21 May 2018 convert ouput of gi_t_cbrt.bat into t_cbrt.c 

#Use gawk -f make_t_cbrt.awk gi_t_cbrt.out

(FNR==1){
  x;
  printf("/*GI produced data for cbrt*/\n");
  printf("/*Created by make_t_cbrt.awk $Revision: 1.3 $ %s from %s*/\n",
	 strftime("%d %b %Y"),FILENAME);
  printf("/*%s*/\n",$0);
  printf("\n");
  printf("const float __t_cbrt[1024] = {\n");
}

#take first solution CMA-ES found
($1=="DONE" && (!($3 in done))) {
  x;
  done[$3]=1;
  #start by not reformating number, although only have float precision
  if($3) {
    x;
    printf(",");
    if(($3/2)%2) printf(" "); else printf("\n"); 
  }
  printf("%s,%s",$4,$5);
}

END{
  printf("\n};\n");
  printf("/*%s*/\n",$0);
}


