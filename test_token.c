#include "token.h"
#include "debug_token.h"
#include <string.h>

#define EXAMPLE_COUNT 4

int main() {
  char * examples[EXAMPLE_COUNT];
  examples[0] = "{\"foo\" : \"bar\"}";
  examples[1] = "\"foobar\"";
  examples[2] = "[\"a\", \"b\", \"c\"]";
  examples[3] = "[1, 2, 3]";
  int i;
  for (i = 0; i < EXAMPLE_COUNT; i++) {
    printf("Parsing {%s} with length {%d}.\n", examples[i], strlen(examples[i]) - 1);
    struct token * tokens = tokenize(strlen(examples[i]) - 1, examples[i]);
    if (tokens == NULL) {
      printf("Tokenize failed.\n");
      return -1;
    }
    print_tokens(tokens);
    printf("\n");
  }
  return 0;
}
