#ifndef _TOKEN_DEBUG_H
#define _TOKENDEBUG_H

#include "debug_token.h"

void print_tokens(struct token * tokens) {
  char * type_info[TOKEN_TYPE_SIZE];
  type_info[TOKEN_OBJ_OPEN] = "OBJ_OPEN";
  type_info[TOKEN_OBJ_CLOSE] = "OBJ_CLOSE";
  type_info[TOKEN_ARRAY_OPEN] = "ARRAY_OPEN";
  type_info[TOKEN_ARRAY_CLOSE] = "ARRAY_CLOSE";
  type_info[TOKEN_SYMBOL] = "SYMBOL";
  type_info[TOKEN_COMMA] = "COMMA";

  // Copy the text into a buffer and null terminate it, so we can printf it.
  char * buffer = malloc(tokens->size + 1);
  int i = 0;
  for(;i < tokens->size; i++) buffer[i] = tokens->bytes[i];
  buffer[tokens->size] = '\0';
  
  printf("{%s|%s}\n", type_info[tokens->type], buffer);

  free(buffer);

  if (tokens->next != NULL) {
    print_tokens(tokens->next);
  }
}

#endif
