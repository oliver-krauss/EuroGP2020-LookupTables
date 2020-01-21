W.Langdon cs.ucl.ac.uk 26 June 2018 based on opencv_ssbse2016/gp/README.txt r1.9 $Revision: 1.6 $

C Cube Root cbrt and log2

Assumes use of Linux tcsh scripts and a recent GNU gcc compiler.

C Code, Unix scripts, etc for:

Evolving Better Software Parameters, William B. Langdon and Justyna Petke,
In SSBSE 2018, Aldeida Aleti and Annibale Panichella (eds.), 8-10 September, Montpellier.
and
Evolving Square Root into Binary Logarithm, W. B. Langdon, 
Technical Report RN/18/05 


Before doing anything -> enter tcsh


The evolved code is accurate to double precision

GGGP project at http://www.cs.ucl.ac.uk/staff/W.Langdon/gggp

We do not include copies of the GNU C library since 
1) you may already have it installed and 2) it is large.
We downloaded glibc-2.27.tar.gz from www.gnu.org/s/libc
Similarly the C version of CMA-ES may be found via
github.com/cma-es/c-cmaes/archive/master.zip
documentation at http://cma.gforge.inria.fr/cmaes_sourcecode_page.html#C

------------------------------------------------------------

Unpack tar file, eg:
gunzip -c gi_cbrt.tar.gz | tar xvf -

The genetic Improvement system is in two directories
gi_glibc/cbrt  for sqrt -> cbrt
gi_glibc/log2  for sqrt -> log2

gi_glibc/cbrt/c-cmaes-master/src/ contains part of CMA-ES


Directories:
gi_glibc/cbrt/cmaes_run
gi_glibc/log2/cmaes_run
contain example output from CMA-ES


A description of some of the more important files in this tar file can
be found at the end of this file.

------------------------------------------------------------
Running CMA-ES

The tcsh script gi_t_cbrt.bat runs CMA-ES (up to ten times) for each of the 512
entries needed for the cube root (or log2) table. It takes an optional
numeric argument, which is the seed for various pseudo random numbers
generators. Typically the seed is six digits. Eg: in directory cbrt/

./gi_t_cbrt.bat 140353 >& gi_t_cbrt.out

(For log2/ perhaps ./gi_t_log2.bat >& gi_t_log2.out )

Run time may vary but for cbrt is typically no more than five minutes.
By default CMA-ES produces a lot of output files.
Most of the time CMA-ES finds suitable pairs of values for the t_cbrt
table. If it does not the script will run CMA-ES again with a different
random seed. It will re-try up to ten times.



Post Evolution Processing
~~~~~~~~~~~~~~
Use gawk to extract the 512 sets of values evolved by CMA-ES
and format them as a C table. Eg:

gawk -f make_t_cbrt.awk gi_t_cbrt.out > t_cbrt.c
gawk -f make_t_log2.awk gi_t_log2.out > t_log2.c

The output of CMA-ES is now ready for use.

In addition to the fitness function, we provide C code and scripts for
testing the evolved values. They should give answers which are accurate
to double precision accuracy.


Compiling
~~~~~~~~~
The tar ball includes images and object files. If you need to
recompile, see the two compile.bat files. They should be treated
with caution as paths, directories, etc. may need adjusting for your
circumstances.

Testing
~~~~~~~
The cbrt/ and log2/ sub-directories include five scripts designed to
test the evolved data values: test.bat test2.bat fuzz_exp.bat fuzz1.bat fuzz_int.bat
test.bat assumes you have built an image main containing the your evolved function
The others assume main2 contains the your evolved function

Running test.bat, chose directory cbrt/ or log2/ then
./test.bat > test.out

test2.bat fuzz_exp.bat fuzz1.bat fuzz_int.bat 
are run in the same way but use main2 (rather than main).



: It will NOT find main unless you append the PATH -> PATH=~/Documents/Dissertation/UCL/cbrt:$PATH

log2/fuzz1.bat log2/fuzz_exp.bat log2/fuzz_int.bat 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
fuzz1.bat etc. generate lots of negative numbers which log2 should
reject. I.e. you should get lots of error.
E.g. in sub directory log2/ run with
fuzz1.bat >& fuzz1.out

Compiling main for test.bat
~~~~~~~~~~~~~~~~~~~~~~~~~~~
cbrt/main
It should be possible to compile main and all the other
cbrt/ images and object files using cbrt/compile.bat
however it makes extensive use of other parts of the GNU C library.
You may need to redefine environment variables BUILD and BUILD2
or edit compile.bat
Also compile.bat will try to compile CMA-ES

log2/main
~~~~~~~~~
gcc -c -g main.c
gcc -o main gi_log2.o main.o -lm

It need be log2/gi_log2.c can be compiled, see log2/compile.bat,
however it makes extensive use of other parts of the GNU C library.
You may need to redefine environment variables BUILD and BUILD2
or edit log2/compile.bat

------------------------------------------------------------

Some of the files

e_sqrt.c          Original sqrt code modified to support cbrt instead
t_sqrt.c          Data file shipped with glibc-2.27
gi_t_cbrt.awk     gawk script to extract data from t_sqrt.c to initialise CMA-ES
gi_t_cbrt.bat     tcsh script to run CMA-ES
cmaes_cbrt        Program linked to CMA-ES containing cbrt fitness function

gi_log2.c         Source code for log2(). Based on sqrt() but includes
		  CMA-ES fitness function fitfun, debug and test code.
cmaes_log2.c      Source code for running CMA-ES on sqrt -> log2 data conversion 
make_t_log2.awk	  gawk script for converting output of gi_t_log2.bat into t_log2.c

test.bat          Run post evolution tests using main linked with evolved data values
		  On 3*512 large positive integers
test2.bat         Run post evolution tests using main2 linked with evolved data values
		  On double precision values given as bit patterns
fuzz1.bat         Run post evolution tests using main2 linked with evolved data values
		  On double precision values given as bit patterns
fuzz_exp.bat      Run post evolution tests using main2 linked with evolved data values
		  On numbers given in scientific notation
fuzz_int.bat      Run post evolution tests using main2 linked with evolved data values
		  On random bit patterns

----------------------------------------------------------------------

Some errors
~~~~~~~~~~~

./gi_t_cbrt.bat: Command not found.

Are you in the cbrt/ sub-directory?


gawk -f make_t_cbrt.awk gi_t_cbrt.out > t_cbrt.c
gawk: fatal: can't open source file `make_t_cbrt.awk' for reading (No such file or directory)

Are you in the cbrt/ sub-directory?


./compile.bat 
cc1: fatal error: /tmp/glibc-2.27/test/build/libc-modules.h: No such file or directory
compilation terminated.
gcc gi_log2.c failed status 1

Did you run configure and make after unpacking the GNU C library (glibc-2.27.tar.gz)
eg:
  mkdir -p test/build
  cd test/build
  setenv build `pwd`
  setenv PATH /opt/rh/devtoolset-7/root/usr/bin/:"$PATH"
  /tmp/glibc-2.27/configure --prefix=$build
  make
Were ./configure and make of glibc successful?
Perhaps your version of glibc is not exactly where compile.bat expects it
See also https://stackoverflow.com/questions/33391636/gnu-c-library-glibc-build-error-libc-modules-h-not-found


main2: gi_log2.c:387: gi_log2: Assertion `0' failed.
Abort

Assertion `0' failed is expected of fuzz_exp.bat fuzz1.bat fuzz_int.bat (see above)
