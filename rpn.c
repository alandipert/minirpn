#include <stdio.h>
#include <stdlib.h>
#include "lex.h"
#include "stack.h"
#include "functions.h"

int main(int argc, char *argv[]) {

  stack *s = NULL;
  token t;
  while(next(&t, stdin)) {
    if(t.type == T_VALUE) {
      stack_push(&s, t.value);
    } else {
      switch(t.symbol[0]) {
        case '+': f_add(&s);
                  break;
        case '-': f_subtract(&s);
                  break;
        case '*': f_multiply(&s);
                  break;
        case '/': f_divide(&s);
                  break;
        case '.': f_print(&s);
                  break;
        case 'q': free_stack(&s);
                  printf("Exiting\n");
                  return 0;
        case 'c': free_stack(&s);
                  s = NULL;
                  printf("Stack cleared.\n");
                  break;
        default : printf("Unknown operator \"%s\"\n", t.symbol);
      }
    }
  }

  free_stack(&s);

  return 0;
}
