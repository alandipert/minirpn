typedef struct stack {
  float value;
  struct stack *next;
} stack;

int stack_empty(stack **s);
void print_stack(stack *s);
void free_stack(stack **s);
void stack_push(stack **s, float value);
float stack_pop(stack **s);
float stack_peek(stack **s);
