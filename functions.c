#include <stdio.h>
#include "stack.h"
#include "functions.h"

void f_add(stack **s) {
  float sum = 0;
  while(!stack_empty(s)) {
    sum += stack_pop(s);
  }
  stack_push(s, sum);
}

void f_subtract(stack **s) {
  float result;
  if(!stack_empty(s)) {
    result = stack_pop(s);
  }
  while(!stack_empty(s)) {
    result = stack_pop(s) - result;
  }
  stack_push(s, result);
}

void f_multiply(stack **s) {
  float result;
  if(!stack_empty(s)) {
    result = stack_pop(s);
  }
  while(!stack_empty(s)) {
    result *= stack_pop(s);
  }
  stack_push(s, result);
}

void f_divide(stack **s) {
  float result;
  if(!stack_empty(s)) {
    result = stack_pop(s);
  }
  while(!stack_empty(s)) {
    result = stack_pop(s) / result;
  }
  stack_push(s, result);
}

void f_print(stack **s) {
  printf("%g\n", stack_peek(s));
}
