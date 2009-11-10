#include <stdio.h>
#include <stdlib.h>
#include "lex.h"
#include "stack.h"

void print_usage() {
  printf("q\tquit\nc\tclear stack\n.\tprint top of stack\n");
}

int main(int argc, char *argv[]) {

  stack *s = NULL;
  token t;
  while(next(&t, stdin)) {
    if(t.type == T_VALUE) {
      stack_push(&s, t.value);
    } else {
      float arg1,arg2;
      switch(t.symbol[0]) {
        case '+': stack_push(&s, stack_pop(&s)+stack_pop(&s));
                  break;
        case '-': arg1 = stack_pop(&s);
                  arg2 = stack_pop(&s);
                  stack_push(&s, arg2-arg1);
                  break;
        case '*': stack_push(&s, stack_pop(&s)*stack_pop(&s));
                  break;
        case '/': arg1 = stack_pop(&s); 
                  arg2 = stack_pop(&s);
                  stack_push(&s, arg2/arg1);
                  break;
        case '.': printf("%g\n", stack_peek(&s));
                  break;
        case 'q': free_stack(&s);
                  printf("Exiting\n");
                  return 0;
        case 'c': free_stack(&s);
                  printf("Stack cleared.\n");
                  break;
        case 'h':
        case '?': print_usage();
                  break;
        default : printf("Unknown operator \"%s\"\n", t.symbol);
      }
    }
  }

  return 0;
}
