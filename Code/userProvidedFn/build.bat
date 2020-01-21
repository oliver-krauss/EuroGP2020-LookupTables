x=Log
if [ ! -z $1 ]; then
  x=$1
fi

seed=140353
if [ ! -z $2 ]; then
  seed=$2
fi

# recompile code in case anything was changed
cmake --build ./cmake-build-debug --target all -- -j 4

# run CMA-ES (automatically builds the lookup table)
cd cmake-build-debug
./cmaesOptimize_$x $seed
cd ..

# recompile with new lookup table
cmake --build ./cmake-build-debug --target all -- -j 4