#!/usr/bin/env bash
# Runs every episode's Python and C++ tests. Usage: ./run_tests.sh
set -euo pipefail
cd "$(dirname "$0")"
build=$(mktemp -d)
trap 'rm -rf "$build"' EXIT
fail=0
for dir in [0-9][0-9]-*/; do
  dir=${dir%/}
  echo "== $dir"
  if ! python3 -m unittest discover -s "$dir" -p "test_*.py" -q; then fail=1; fi
  for t in "$dir"/test_*.cpp; do
    [ -e "$t" ] || continue
    bin="$build/$(basename "$t" .cpp)"
    if g++ -std=c++17 -Wall -Wextra -Werror -O2 "$t" -o "$bin" && "$bin"; then
      echo "C++ OK  $(basename "$t")"
    else
      echo "C++ FAIL $(basename "$t")"; fail=1
    fi
  done
done
[ $fail -eq 0 ] && echo "All tests passed ✅" || { echo "Some tests failed ❌"; exit 1; }
