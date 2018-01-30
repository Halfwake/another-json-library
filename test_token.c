#include "token.h"
#include "debug_token.h"
#include <string.h>

int main() {
  char * example1 = "{\"foo\" : \"bar\"}";
  size_t length1 = strlen(example1) - 1;
  printf("Parsing {%s} with length {%d}.\n", example1, length1);
  struct token * tokens = tokenize(length1, example1);
  if (tokens == NULL) {
    printf("Tokenize failed.\n");
    return -1;
  }
  print_tokens(tokens);
  return 0;
}
