#include <stdlib.h>

enum TOKEN_TYPE {
  TOKEN_OBJ_OPEN,
  TOKEN_OBJ_CLOSE,
  TOKEN_ARRAY_OPEN,
  TOKEN_ARRAY_CLOSE,
  TOKEN_SYMBOL,
  TOKEN_COMMA,
  TOKEN_TYPE_SIZE,
};

struct token {
  enum TOKEN_TYPE type;
  char * bytes;
  int static_allocation;
  size_t size;
  struct token * next;
};

/*
 * Take a string and return an internally linked list of tokens.
 */
struct token * tokenize(size_t size, char * buffer);

struct token * new_token(enum TOKEN_TYPE type, char * bytes, size_t size);

struct token * push_token(struct token * stack, struct token * new);
