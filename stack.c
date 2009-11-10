#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void print_stack(stack *s) {
  if(s != NULL) {
    printf("%g", s->value);
    if(s->next != NULL) {
      printf(" ");
      print_stack(s->next);
    } else {
      printf("\n");
    }
  }
}

void free_stack(stack **s) {
  if(!stack_empty(s)) {
    stack *next;
    while((next = (*s)->next) != NULL) {
      free(*s);
      free_stack(&next);
    }
  }
  *s = NULL;
}

static stack* stack_mk(float value) {
  stack *s = (stack*)malloc(sizeof(stack));
  s->value = value;
  s->next = NULL;
  return s;
}

void stack_push(stack **s, float value) {
  if(s == NULL) {
    *s = stack_mk(value);
  } else {
    stack *new_s = stack_mk(value);
    new_s->next = *s;
    *s = new_s;
  }
}

int stack_empty(stack **s) {
  return (*s == NULL || *s < 0);
}

float stack_pop(stack **s) {
  if(stack_empty(s)) {
    fprintf(stderr, "Error: stack underflow\n");
    return 0;
  } else {
    stack *popped_s = *s;
    float popped_v = popped_s->value;
    *s = popped_s->next;
    free(popped_s);
    return popped_v;
  }
}

float stack_peek(stack **s) {
  if(stack_empty(s)) {
    fprintf(stderr, "Error: stack underflow\n");
    return 0;
  } else {
    return (*s)->value;
  }
}
