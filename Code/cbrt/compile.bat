#WBL 18 May 2018 from gi_glibc/glibc-2.27_config_make.script $Revision: 1.7 $

#WBL 27 Jun 2018 For release kit combine with compile2.bat and ../cbrt/compile.bat
#                improve error reports

#use gcc version 7.2.1 20170829 (Red Hat 7.2.1-1) (GCC)
setenv PATH /opt/rh/devtoolset-7/root/usr/bin/:$PATH

#cd /tmp/glibc-2.27/test/build/locale
setenv BUILD2 /opt/glibc/glibc-2.27/compile
setenv BUILD  /opt/glibc/glibc-2.27

#Notes
# originally for x86_64
# left-right order of include files (and their directories) vital
# -MF /tmp/glibc-2.27/test/build/math/e_sqrt.o.d not so helpful
# -I$BUILD/sysdeps/x86/bits exactly wrong approach
# -v useful debug aid

gcc	\
    -fmax-errors=1	\
    e_sqrt.c	\
    -c	\
    -std=gnu11	\
    -fgnu89-inline	\
    -O2	\
    -Wall	\
    -Werror	\
    -Wundef	\
    -Wwrite-strings	\
    -fmerge-all-constants	\
    -fno-stack-protector	\
    -frounding-math	\
    -g	\
    -Wstrict-prototypes	\
    -Wold-style-definition	\
    -ffp-contract=off	\
    -D__NO_MATH_INLINES	\
    -D__LIBC_INTERNAL_MATH_INLINES	\
    -I$BUILD/include	\
    -I$BUILD/math	\
    -I.	\
    -I$BUILD/sysdeps/unix/sysv/linux/x86_64/64	\
    -I$BUILD/sysdeps/unix/sysv/linux/x86_64	\
    -I$BUILD/sysdeps/unix/sysv/linux/x86	\
    -I$BUILD/sysdeps/x86/nptl	\
    -I$BUILD/sysdeps/unix/sysv/linux/wordsize-64	\
    -I$BUILD/sysdeps/x86_64/nptl	\
    -I$BUILD/sysdeps/unix/sysv/linux/include	\
    -I$BUILD/sysdeps/unix/sysv/linux	\
    -I$BUILD/sysdeps/nptl	\
    -I$BUILD/sysdeps/pthread	\
    -I$BUILD/sysdeps/gnu	\
    -I$BUILD/sysdeps/unix/inet	\
    -I$BUILD/sysdeps/unix/sysv	\
    -I$BUILD/sysdeps/unix/x86_64	\
    -I$BUILD/sysdeps/unix	\
    -I$BUILD/sysdeps/posix	\
    -I$BUILD/sysdeps/x86_64/64	\
    -I$BUILD/sysdeps/x86_64/fpu/multiarch	\
    -I$BUILD/sysdeps/x86_64/fpu	\
    -I$BUILD/sysdeps/x86/fpu/include	\
    -I$BUILD/sysdeps/x86/fpu	\
    -I$BUILD/sysdeps/x86_64/multiarch	\
    -I$BUILD/sysdeps/x86_64	\
    -I$BUILD/sysdeps/x86	\
    -I$BUILD/sysdeps/ieee754/float128	\
    -I$BUILD/sysdeps/ieee754/ldbl-96/include	\
    -I$BUILD/sysdeps/ieee754/ldbl-96	\
    -I$BUILD/sysdeps/ieee754/dbl-64/wordsize-64	\
    -I$BUILD/sysdeps/ieee754/dbl-64	\
    -I$BUILD/sysdeps/ieee754/flt-32	\
    -I$BUILD/sysdeps/wordsize-64	\
    -I$BUILD/sysdeps/ieee754	\
    -I$BUILD/sysdeps/generic	\
    -I$BUILD	\
    -I$BUILD/libio	\
    -D_LIBC_REENTRANT	\
    -include $BUILD2/libc-modules.h	\
    -DMODULE_NAME=libm	\
    -I$BUILD2	\
    -include $BUILD/include/libc-symbols.h	\
    -DTOP_NAMESPACE=glibc	\
    -I$BUILD/soft-fp	\
    -o e_sqrt.o

#    -MD	\
#    -MP	\
#    -MF	\
#    $BUILD/math/e_sqrt.o.dt	\
#    -MT	\
#    $BUILD/math/e_sqrt.o

setenv save $status
if($save) then
  echo "gcc e_sqrt.c failed status $save"
  rm -f e_sqrt.o
  exit $save
endif

gcc -c main.c

setenv save $status
if($save) then
  echo "gcc main.c failed status $save"
  rm -f main.o
  exit $save
endif

gcc -o main e_sqrt.o main.o

setenv save $status
if($save) then
  echo "link failed status $save"
  rm -f main
  exit $save
endif

##############################################################################
#WBL 19 May 2018 from gi_glibc/glibc-2.27_config_make.script. r1.3a
#based on compile.bat r1.6

#use gcc version 7.2.1 20170829 (Red Hat 7.2.1-1) (GCC)
#setenv PATH /opt/rh/devtoolset-7/root/usr/bin/:$PATH

#cd /tmp/glibc-2.27/test/build/locale
#setenv BUILD2 /tmp/glibc-2.27/test/build
#setenv BUILD  /tmp/glibc-2.27

#Notes
# originally for x86_64
# left-right order of include files (and their directories) vital
# -MF /tmp/glibc-2.27/test/build/math/e_sqrt.o.d not so helpful
# -I$BUILD/sysdeps/x86/bits exactly wrong approach
# -v useful debug aid

gcc	\
    -fmax-errors=1	\
    gi_cbrt.c	\
    -c	\
    -std=gnu11	\
    -fgnu89-inline	\
    -O2	\
    -Wall	\
    -Werror	\
    -Wundef	\
    -Wwrite-strings	\
    -fmerge-all-constants	\
    -fno-stack-protector	\
    -frounding-math	\
    -g	\
    -Wstrict-prototypes	\
    -Wold-style-definition	\
    -ffp-contract=off	\
    -D__NO_MATH_INLINES	\
    -D__LIBC_INTERNAL_MATH_INLINES	\
    -I$BUILD/include	\
    -I$BUILD/math	\
    -I.	\
    -I$BUILD/sysdeps/unix/sysv/linux/x86_64/64	\
    -I$BUILD/sysdeps/unix/sysv/linux/x86_64	\
    -I$BUILD/sysdeps/unix/sysv/linux/x86	\
    -I$BUILD/sysdeps/x86/nptl	\
    -I$BUILD/sysdeps/unix/sysv/linux/wordsize-64	\
    -I$BUILD/sysdeps/x86_64/nptl	\
    -I$BUILD/sysdeps/unix/sysv/linux/include	\
    -I$BUILD/sysdeps/unix/sysv/linux	\
    -I$BUILD/sysdeps/nptl	\
    -I$BUILD/sysdeps/pthread	\
    -I$BUILD/sysdeps/gnu	\
    -I$BUILD/sysdeps/unix/inet	\
    -I$BUILD/sysdeps/unix/sysv	\
    -I$BUILD/sysdeps/unix/x86_64	\
    -I$BUILD/sysdeps/unix	\
    -I$BUILD/sysdeps/posix	\
    -I$BUILD/sysdeps/x86_64/64	\
    -I$BUILD/sysdeps/x86_64/fpu/multiarch	\
    -I$BUILD/sysdeps/x86_64/fpu	\
    -I$BUILD/sysdeps/x86/fpu/include	\
    -I$BUILD/sysdeps/x86/fpu	\
    -I$BUILD/sysdeps/x86_64/multiarch	\
    -I$BUILD/sysdeps/x86_64	\
    -I$BUILD/sysdeps/x86	\
    -I$BUILD/sysdeps/ieee754/float128	\
    -I$BUILD/sysdeps/ieee754/ldbl-96/include	\
    -I$BUILD/sysdeps/ieee754/ldbl-96	\
    -I$BUILD/sysdeps/ieee754/dbl-64/wordsize-64	\
    -I$BUILD/sysdeps/ieee754/dbl-64	\
    -I$BUILD/sysdeps/ieee754/flt-32	\
    -I$BUILD/sysdeps/wordsize-64	\
    -I$BUILD/sysdeps/ieee754	\
    -I$BUILD/sysdeps/generic	\
    -I$BUILD	\
    -I$BUILD/libio	\
    -D_LIBC_REENTRANT	\
    -include $BUILD2/libc-modules.h	\
    -DMODULE_NAME=libm	\
    -I$BUILD2	\
    -include $BUILD/include/libc-symbols.h	\
    -DTOP_NAMESPACE=glibc	\
    -I$BUILD/soft-fp	\
    -o gi_cbrt.o

#    -MD	\
#    -MP	\
#    -MF	\
#    $BUILD/math/e_sqrt.o.dt	\
#    -MT	\
#    $BUILD/math/e_sqrt.o

setenv save $status
if($save) then
  echo "gcc gi_cbrt.c failed status $save"
  rm -f gi_cbrt.o >& /dev/null
  exit $save
endif

gcc -c -g main2.c

setenv save $status
if($save) then
  echo "gcc main2.c failed status $save"
  rm -f main2.o
  exit $save
endif

#neither input nor t_cbrt_idx should be used by main2.c
gcc -o main2 gi_cbrt.o main2.o -lm	\
    -Xlinker --defsym=input=0		\
    -Xlinker --defsym=t_cbrt_idx=0

setenv save $status
if($save) then
  echo "link main2 failed status $save"
  rm -f main2 >& /dev/null
  exit $save
endif
##############################################################################
#WBL 20 May 2018 based on cmaes compile. r1.3

gcc -g -c -O2 -ansi -pedantic	\
  -Wall -Wextra -Wstrict-prototypes -Wmissing-prototypes -Wshadow	\
  -Wno-pedantic 		    			 		\
  cmaes_cbrt.c -Ic-cmaes-master/src/ c-cmaes-master/src/cmaes.c

setenv save $status
if($save) then
  echo "compile cmaes_cbrt.c or cmaes.c failed. Status $save"
  rm -f cmaes_cbrt.o cmaes.o >& /dev/null
  exit $save
endif

gcc -o cmaes_cbrt cmaes_cbrt.o cmaes.o gi_cbrt.o -lm

# -Wconversion gives unfortunately a warning if int instead of long is passed to a function
# -pg : gnu profiler for gprof 
# -g: debugger
# -pedantic-errors: like pedantic, except that errors are produced instead of warnings
# -c : compile only

setenv save $status
if($save) then
  echo "link cmaes_cbrt failed status $save"
  rm -f cmaes_cbrt >& /dev/null
  exit $save
endif
##############################################################################
