#define T_VALUE 1
#define T_SYMBOL 2

typedef struct token {
  float value;
  int type;
  char symbol[255];
} token;

int next(token *t, FILE *f);
