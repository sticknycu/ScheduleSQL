#!/usr/bin/env bash

set -e

export SCHEDULESQL_BUILD_SERIES_NAME="Travis $CC $TRAVIS_SCHEDULESQL_BUILD_TYPE"
export SCHEDULESQL_BUILD_ID=$TRAVIS_JOB_NUMBER
export SCHEDULESQL_BUILD_DATETIME=$(date)

# Use ccache if available
if [ $(which ccache) ]; then
  # Re-run compile on pre-processed sources on cache miss
  # "It's slower actually, but clang builds fail without it."
  export CCACHE_CPP2=true

  # Tell CMake of ccache's existence
  CACHE_ARGS="-DCMAKE_C_COMPILER_LAUNCHER=ccache -DCMAKE_CXX_COMPILER_LAUNCHER=ccache"

  echo "Using ccache installed at $(which ccache)"
  ccache --max-size=1G
  ccache --zero-stats
fi

# Work around a Clang + ccache issue with failing builds by disabling
# precompiled headers. Turn off LTO for faster build speeds
cmake . -DCMAKE_BUILD_TYPE=${TRAVIS_SCHEDULESQL_BUILD_TYPE} \
  -DBUILD_TOOLS=Yes \
  -DPRECOMPILE_HEADERS=No \
  -DSELF_TEST=Yes \
  -DUNITY_BUILDS=${TRAVIS_SCHEDULESQL_UNITY_BUILDS-Yes} \
  -DWHOLE_PROGRAM_OPTIMISATION=No \
  ${CACHE_ARGS}

echo "Building..."
cmake --build . --parallel 2

if [ $(which ccache) ]; then
  echo "Built with ccache, outputting cache stats..."
  ccache --show-stats
fi

echo "Testing..."
ctest --output-on-failure --parallel 2

if [ "$TRAVIS_SCHEDULESQL_BUILD_TYPE" != "COVERAGE" ]; then
  chmod +x ScheduleSQL
  ./ScheduleSQL -c schedulesql.json -t root
  cd root
  FILE=schedulesql.json
  if [ -f "$FILE" ]; then
    echo "$FILE exists so it's ok."
  else
    echi "$FILE do not exist, so it's not ok."
    exit 1
  fi
  EOF
  ./ScheduleSQL -d schedulesql.json -t root
  cd root
  FILE=schedulesql.json
  if [ -f "$FILE" ]; then
    echo "$FILE exists so it's not ok."
    exit 1
  else
    echi "$FILE do not exist, so it's ok."
  fi
  EOF
fi
