#WBL 20 May 2018 reading numbers for PowerPC sqrt $Revision: 1.1 $

#Use gawk -f gi_t_cbrt.awk t_sqrt.c

(substr($0,2,1)=="."){
  n=split($0,t,"[ ,]");
  for(i=1;i<=n;i++) if(t[i]) data[I++]=t[i];
}
END{
  #print I;
  for(i=0;i<I;i+=2){
  a=data[i]-1;  b=data[i+1]-0.5;
  suma  += a;   sumb  += b;
  sum2a += a*a; sum2b += b*b;
  }
  n=I/2;
  meana = suma/n;
  meanb = sumb/n;
  vara = sum2a/n - meana*meana;
  varb = sum2b/n - meanb*meanb;
  if(g!="") {
    x;
    #use only data for 1..2 in __t_sqrt
    #if even use mid point, if odd round up
    if(g%2==0 && g<510) {
      x;
      i=g+512;
      printf("%f %f ",(data[i]+data[i+2])/2,(data[i+1]+data[i+3])/2);
    } else {
      x;
      i=(g+1)+512;
      if(i>1022) i=1022;
      printf("%f %f ",data[i],data[i+1]);
    }
  }
  if(r=="") r=3.0;
  print r*sqrt(vara),r*sqrt(varb);
}


