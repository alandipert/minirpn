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

exit 0
