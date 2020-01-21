#WBL 20 May 2018 Use CMA-ES to tune __t_cbrt 
#based on RE_gp.bat r1.93

# TODO - switch to CSH

#seed     $1  #not too many digits
setenv seed 140353
if($1) setenv seed $1

echo "$0 seed $seed" '$Revision: 1.10 $' $HOST `pwd` `date`

#start by reading numbers for PowerPC sqrt

set g=0
while ( $g < 512 )
  set h=0
  set testpoint=(`gawk -v "g=$g" 'END{print 1+g/512+1/1024}' /dev/null`)
  setenv start_point `gawk -v "g=$g" -f gi_t_cbrt.awk t_sqrt.c`
  if($status) exit $status;
  while ( $h < 10 )
    rm -f outcmaes*.dat >&/dev/null
    echo "./cmaes_cbrt $testpoint $g$h$seed $start_point"
    ./cmaes_cbrt $testpoint $g$h$seed $start_point >! /tmp/gi_t_cbrt.tmp
    if($status) exit $status;
    grep ^DONE /tmp/gi_t_cbrt.tmp
    setenv save $status
    if($save) then
      set h=(`expr $h + 1`)
    else
      set h=11
    endif
  end
  grep ^DONE /tmp/gi_t_cbrt.tmp
  if($save) then
    echo "grep ^DONE /tmp/gi_t_cbrt.tmp failed $save on g=$g h=$h testpoint=$testpoint "
  endif
  set g=(`expr $g + 1`)
end

#  else
#    setenv next_point `gawk '($1=="DONE"){ok=1;print $4,$5;exit}END{exit (ok)? 0:1}' /tmp/gi_t_cbrt.tmp`
#    if($status) exit $status;
#    echo "./cmaes_cbrt $testpoint $g$seed $next_point "
#    ./cmaes_cbrt $testpoint $g$seed $next_point >! /tmp/gi_t_cbrt.tmp
#    if($status) exit $status;
#  endif

echo "$0 done" `date`
