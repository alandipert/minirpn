#!/bin/bash

function try {
  if [ "$(echo "$1 ." | ./rpn)" = "$2" ]; then
    echo "\e[32;40mPASS\033[0m\t$3\t$1"
  else
    echo "\e[31;40mFAIL\033[0m\t$3\t$1" >&2
    exit 1
  fi
}

try "10 10 +" "20" "Addition"
try "100 1 -" "99" "Subtraction"
try "10.2 2 *" "20.4" "Multiplication"
try "33 3 /" "11" "Division"
try "10 10 + 4 / 20 * 50 -" "50" "Expression"

exit 0
