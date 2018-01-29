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
 * @param tokens The size of the buffer. Null terminators are ignored.
 * @param buffer The string buffer. Null terminators don't change
 *               behavior. These buffer will be referenced by the return value.
 * @return A list of the tokens inside the text.
 */
struct token * tokenize(size_t size, char * buffer);
