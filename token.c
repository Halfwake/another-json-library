#include "token.h"

struct token * new_token(enum TOKEN_TYPE type, char * bytes, size_t size) {
  struct token * token = malloc(sizeof(struct token));
  token->type = type;
  token->bytes = bytes;
  token->size = size;
  token->next = NULL;
  return token;
}

struct token * push_token(struct token * stack, struct token * new) {
  if (stack == NULL) {
    return new;
  } else {
    new->next = stack;
    return new;
  }
}

struct token * tokenize(size_t size, char * buffer) {
  struct token * head = NULL;
  size_t index = 0;
  size_t str_start = -1;
  while (index <= size) {
    switch (buffer[index]) {
    case '{':
      head = push_token(head, new_token(TOKEN_OBJ_OPEN, "{", 1));
      index++;
      break;
    case '}':
      head = push_token(head, new_token(TOKEN_OBJ_CLOSE, "}", 1));
      index++;
      break;
    case '[':
      head = push_token(head, new_token(TOKEN_ARRAY_OPEN, "[", 1));
      index++;
      break;
    case ']':
      head = push_token(head, new_token(TOKEN_ARRAY_CLOSE, "]", 1));
      index++;
      break;
    case ',':
      head = push_token(head, new_token(TOKEN_COMMA, ",", 1));
      index++;
      break;
    case '"':
      str_start = index + 1;
      if (str_start >= size) return NULL; //TODO! Die, expected " but got end of buffer
      index++;
      while (buffer[index] != '"') {
	if (index >= size) return NULL; //TODO! Die, expected " but got end of buffer.
	index++;
      }      
      head = push_token(head, new_token(TOKEN_SYMBOL, buffer + str_start, index - str_start));
      index++;
      break;
    case ':':
      head = push_token(head, new_token(TOKEN_OBJ_SPLIT, ":", 1));
      index++;
      break;
    case ' ':
    case '\t':
    case '\n':
      index++;
      break;
    default:
      return NULL;
      //TODO! Die, hard!
    }
  }
  return head;
}
