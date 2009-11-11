#!/bin/bash

function try {
  local res=$(echo "$1 ." | ./rpn)
  if [ $res = $2 ]; then
    echo -e "\e[32;40m[ ✔ ]\033[0m\t$res = $1"
  else
    echo -e "\e[31;40m[ ✖ ]\033[0m\t$res != $1, should be $2" >&2
    exit 1
  fi
}

try '10 10 +' '20'
try '100 1 -' '99'
try '10.2 2 *' '20.4'
try '33 3 /' '11'
try '10 10 + 4 / 20 * 50 -' '50'
try '10 2 ^' '100'

exit 0
