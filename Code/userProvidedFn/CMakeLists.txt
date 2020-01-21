cmake_minimum_required(VERSION 3.14)
project(userProvidedFn C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER "gcc")
set(GLIBC "/opt/glibc/glibc-2.27")
set(GLIBC_COMPILED "/opt/glibc/glibc-2.27/compile")
set(CMAES "./c-cmaes-master/src")

set(SQRT userProvidedFunctionSqrt.c)
set(CBRT userProvidedFunctionCbrt.c)
set(SURT userProvidedFunctionSurt.c)
set(INFL userProvidedFunctionInflection.c)
set(MULINFL userProvidedFunctionInflectionMulti.c)

# the amount of compilation options is getting rididculous. To test with a different user function modify the following
set(UF ${SQRT})

set(DEFAULT_FILES userProvidedFunction.h ${UF} lookupTable.h newtonianApproximation.c newtonianApproximation.h helperFunctions.c helperFunctions.h)
set(CMAES_FILES lookupTableArchetype.c fitfun.h cmaesRunner.c ${CMAES}/cmaes.c ${CMAES}/cmaes.h ${CMAES}/cmaes_interface.h)

#
#add_definitions(${GCC_FLAGS})

#file(GLOB_RECURSE OBJS
#        "${GLIBC}/*.*"
#        "${GLIBC_COMPILED}/*.*"
#        )
#
#set_source_files_properties(
#        ${OBJS}
#        PROPERTIES
#        EXTERNAL_OBJECT true
#        GENERATED true
#)
configure_file(cmaes.par ${PROJECT_BINARY_DIR}/cmaes.par COPYONLY)

# UF Definitions for testing the FFN -> With -1/2 center 1/2 test points
add_executable(uF_Bitdiff main.c lookupTableBitdiff.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_Bitdiff m)
add_executable(uF_BitdiffVA main.c lookupTableBitdiffVA.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_BitdiffVA m)
add_executable(uF_HardLog main.c lookupTableHardLog.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_HardLog m)
add_executable(uF_HardLogVA main.c lookupTableHardLogVA.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_HardLogVA m)
add_executable(uF_Log main.c lookupTableLog.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_Log m)
add_executable(uF_LogVA main.c lookupTableLogVA.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_LogVA m)
add_executable(uF_Mul main.c lookupTableMul.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_Mul m)
add_executable(uF_MulVA main.c lookupTableMulVA.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_MulVA m)
add_executable(uF_NoLog main.c lookupTableNoLog.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_NoLog m)
add_executable(uF_NoLogVA main.c lookupTableNoLogVA.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_NoLogVA m)

# UF Definitions for testing the FFN -> With -1/3 center 1/3 test points
add_executable(uF_DistrBitdiff main.c lookupTableDistrBitdiff.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_DistrBitdiff m)
add_executable(uF_DistrBitdiffVA main.c lookupTableDistrBitdiffVA.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_DistrBitdiffVA m)
add_executable(uF_DistrHardLog main.c lookupTableDistrHardLog.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_DistrHardLog m)
add_executable(uF_DistrHardLogVA main.c lookupTableDistrHardLogVA.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_DistrHardLogVA m)
add_executable(uF_DistrLog main.c lookupTableDistrLog.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_DistrLog m)
add_executable(uF_DistrLogVA main.c lookupTableDistrLogVA.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_DistrLogVA m)
add_executable(uF_DistrMul main.c lookupTableDistrMul.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_DistrMul m)
add_executable(uF_DistrMulVA main.c lookupTableDistrMulVA.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_DistrMulVA m)
add_executable(uF_DistrNoLog main.c lookupTableDistrNoLog.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_DistrNoLog m)
add_executable(uF_DistrNoLogVA main.c lookupTableDistrNoLogVA.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_DistrNoLogVA m)

# UF Definitions for testing the FFN -> With center point ONLY
add_executable(uF_CenterBitdiff main.c lookupTableCenterBitdiff.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_CenterBitdiff m)
add_executable(uF_CenterBitdiffVA main.c lookupTableCenterBitdiffVA.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_CenterBitdiffVA m)
add_executable(uF_CenterBitdiffFN main.c lookupTableCenterBitdiffFN.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_CenterBitdiffFN m)
add_executable(uF_CenterHardLog main.c lookupTableCenterHardLog.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_CenterHardLog m)
add_executable(uF_CenterHardLogVA main.c lookupTableCenterHardLogVA.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_CenterHardLogVA m)
add_executable(uF_CenterHardLogFN main.c lookupTableCenterHardLogFN.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_CenterHardLogFN m)
add_executable(uF_CenterLog main.c lookupTableCenterLog.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_CenterLog m)
add_executable(uF_CenterLogVA main.c lookupTableCenterLogVA.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_CenterLogVA m)
add_executable(uF_CenterLogFN main.c lookupTableCenterLogFN.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_CenterLogFN m)
add_executable(uF_CenterMul main.c lookupTableCenterMul.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_CenterMul m)
add_executable(uF_CenterMulVA main.c lookupTableCenterMulVA.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_CenterMulVA m)
add_executable(uF_CenterMulFN main.c lookupTableCenterMulFN.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_CenterMulFN m)
add_executable(uF_CenterNoLog main.c lookupTableCenterNoLog.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_CenterNoLog m)
add_executable(uF_CenterNoLogVA main.c lookupTableCenterNoLogVA.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_CenterNoLogVA m)
add_executable(uF_CenterNoLogFN main.c lookupTableCenterNoLogFN.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(uF_CenterNoLogFN m)


#CMAES Run Definitions for Log and noLog -> With -1/2 center 1/2 test points
add_executable(cmaesOptimize_Bitdiff fitfunBitdiff.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_Bitdiff m)
add_executable(cmaesOptimize_BitdiffVA fitfunBitdiffVA.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_BitdiffVA m)
add_executable(cmaesOptimize_HardLog fitfunHardLog.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_HardLog m)
add_executable(cmaesOptimize_HardLogVA fitfunHardLogVA.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_HardLogVA m)
add_executable(cmaesOptimize_Log fitfunLog.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_Log m)
add_executable(cmaesOptimize_LogVA fitfunLogVA.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_LogVA m)
add_executable(cmaesOptimize_Mul fitfunMul.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_Mul m)
add_executable(cmaesOptimize_MulVA fitfunMulVA.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_MulVA m)
add_executable(cmaesOptimize_NoLog fitfunNoLog.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_NoLog m)
add_executable(cmaesOptimize_NoLogVA fitfunNoLogVA.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_NoLogVA m)

#CMAES Run Definitions for Log and noLog -> With -1/3 center 1/3 test points
add_executable(cmaesOptimize_DistrBitdiff fitfunDistrBitdiff.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_DistrBitdiff m)
add_executable(cmaesOptimize_DistrBitdiffVA fitfunDistrBitdiffVA.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_DistrBitdiffVA m)
add_executable(cmaesOptimize_DistrHardLog fitfunDistrHardLog.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_DistrHardLog m)
add_executable(cmaesOptimize_DistrHardLogVA fitfunDistrHardLogVA.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_DistrHardLogVA m)
add_executable(cmaesOptimize_DistrLog fitfunDistrLog.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_DistrLog m)
add_executable(cmaesOptimize_DistrLogVA fitfunDistrLogVA.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_DistrLogVA m)
add_executable(cmaesOptimize_DistrMul fitfunDistrMul.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_DistrMul m)
add_executable(cmaesOptimize_DistrMulVA fitfunDistrMulVA.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_DistrMulVA m)
add_executable(cmaesOptimize_DistrNoLog fitfunDistrNoLog.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_DistrNoLog m)
add_executable(cmaesOptimize_DistrNoLogVA fitfunDistrNoLogVA.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_DistrNoLogVA m)

#CMAES Run Definitions for Log and noLog -> With center point only
add_executable(cmaesOptimize_CenterBitdiff fitfunCenterBitdiff.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_CenterBitdiff m)
add_executable(cmaesOptimize_CenterBitdiffVA fitfunCenterBitdiffVA.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_CenterBitdiffVA m)
add_executable(cmaesOptimize_CenterBitdiffFN fitfunCenterBitdiffFN.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_CenterBitdiffFN m)
add_executable(cmaesOptimize_CenterHardLog fitfunCenterHardLog.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_CenterHardLog m)
add_executable(cmaesOptimize_CenterHardLogVA fitfunCenterHardLogVA.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_CenterHardLogVA m)
add_executable(cmaesOptimize_CenterHardLogFN fitfunCenterHardLogFN.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_CenterHardLogFN m)
add_executable(cmaesOptimize_CenterLog fitfunCenterLog.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_CenterLog m)
add_executable(cmaesOptimize_CenterLogVA fitfunCenterLogVA.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_CenterLogVA m)
add_executable(cmaesOptimize_CenterLogFN fitfunCenterLogFN.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_CenterLogFN m)
add_executable(cmaesOptimize_CenterMul fitfunCenterMul.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_CenterMul m)
add_executable(cmaesOptimize_CenterMulVA fitfunCenterMulVA.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_CenterMulVA m)
add_executable(cmaesOptimize_CenterMulFN fitfunCenterMulFN.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_CenterMulFN m)
add_executable(cmaesOptimize_CenterNoLog fitfunCenterNoLog.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_CenterNoLog m)
add_executable(cmaesOptimize_CenterNoLogVA fitfunCenterNoLogVA.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_CenterNoLogVA m)
add_executable(cmaesOptimize_CenterNoLogFN fitfunCenterNoLogFN.c ${DEFAULT_FILES} ${CMAES_FILES})
target_link_libraries(cmaesOptimize_CenterNoLogFN m)

add_executable(userProvidedFnBench lookupTableArchetype.c bench.c ${DEFAULT_FILES}) #${OBJS}
target_link_libraries(userProvidedFnBench m)

# Comparison Targets for C
add_executable(sqrtC sqrtComparison.c helperFunctions.c)
target_link_libraries(sqrtC m)
add_executable(surtC surtComparison.c helperFunctions.c)
target_link_libraries(surtC m)