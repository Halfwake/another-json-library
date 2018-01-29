#ifndef _JSON_H
#define _JSON_H

#include <stddef.h>

struct json_any;

enum JSON_TYPE {
  JSON_ARRAY_TYPE,
  JSON_OBJ_TYPE,
  JSON_NUM_TYPE,
  JSON_STR_TYPE,
  JSON_TYPE_SIZE,
};

struct json_array {
  size_t size;
  struct json_any * items;
};

struct json_obj {
  size_t size;
  struct json_str * keys;
  struct json_any * vals;
};

struct json_num {
  double value;
};

struct json_str {
  size_t size;
  char * bytes;
};

struct json_any {
  enum json_type type;
  union {
    struct json_array * data;
    struct json_obj * data;
    struct json_num * data;
    struct json_str * daata;
  } data;
};

struct json_any * new_json_array(size_t size, struct json_any * items);
void free_json_array(struct json_array * json);

struct json_any * new_json_obj(size_t size, struct json_str * keys, struct json_any * vals);
void free_json_obj(struct json_obj * json);

struct json_any * new_json_str(size_t size, char * bytes);
void free_json_str(struct json_str * json);

struct json_any * new_json_num(double value);
void free_json_num(struct json_num * json);

void free_json_any(struct json_any * json);

#endif
