#!/bin/tcsh
#WBL 21 May 2018 test GI version of cbrt based on test.bat r1.8

setenv seed 153504
if( $1 != "" ) setenv seed $1

echo $0 '$Revision: 1.0 $' $seed $HOST `pwd` `date`

# overall Comparison
# Went from -100 to 100 in icrements of 1
# The following is the SUM of ABS(Cbrt*cbrt*cbrt - OriginalValue)
#ERROR C    1.2452261444195756E-12
#ERROR CPP  2.0907719999740948E-12
#ERROR Java 1.4015455462867976E-12


# interesting numbers
set pi=3.141592653589793
set e=2.718281828459045

# positive / negative borders
set doubleMax=1.7976931348623157E308;
set doubleMin=-1.7976931348623157E308;
set doublePositiveInfinity=1.7976931348623158E308;
set doubleNegativeInfinity=-1.7976931348623158E308;

# smallest increments / decrements from 0 and 1
set almostPositive0Double=4.9E-324
set almostNegative0Double=-4.9E-324
set almostPositive1Double=1.0000000000000002
set almostNegative1Double=0.9999999999999999
set almostPositive0Float=1.401298464324817E-45
set almostNegative0Float=-1.401298464324817E-45
set almostPositive1Float=1.0000001192092896
set almostNegative1Float=0.9999999403953552

# really small numbers
set beforeDenorm=1.0E-307
set denorm=1.0E-308
set smallestNumber=1.0E-309
set negativebeforeDenorm=-1.0E-307
set negativedenorm=-1.0E-308
set negativesmallestNumber=-1.0E-309

set x=2

# Test C
./main2 $x

# Test C++
../cbrtCpp/cmake-build-debug/cbrtCpp $x

# Java
java -jar ../cbrtJava/target/cbrtJava.jar $x

#
