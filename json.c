#include "json.h"
#include <stdlib.h>

void free_json_any(struct json_any * json) {
  switch (json->type){
  case JSON_ARRAY_TYPE:
    free_json_array(json->data.array);
    break;
  case JSON_OBJ_TYPE:
    free_json_obj(json->data.obj);
    break;
  case JSON_NUM_TYPE:
    free_json_num(json->data.num);
    break;
  case JSON_STR_TYPE:
    free_json_str(json->data.str);
    break;
  }
  free(json);
}

struct json_any * new_json_array(size_t size, struct json_any * items) {
  struct json_any * any = malloc(sizeof(struct json_any));
  struct json_array * array = malloc(sizeof(struct json_array));
  any->type = JSON_ARRAY_TYPE;

  array->size = size;
  array->items = items;
  any->data.array = array;

  return any;
}

void free_json_array(struct json_array * json) {
  size_t i = 0;
  for (;i < json->size; i++) {
    free_json_any(json->items + i);
  }
  free(json);
}

struct json_any * new_json_obj(size_t size, struct json_str * keys, struct json_any * vals) {
  struct json_any * any = malloc(sizeof(struct json_any));
  struct json_obj * obj = malloc(sizeof(struct json_obj));
  any->type = JSON_OBJ_TYPE;

  obj->size = size;
  obj->keys = keys;
  obj->vals = vals;
  any->data.obj = obj;

  return any;
}

void free_json_obj(struct json_obj * json) {
  size_t i = 0;
  for (;i < json->size; i++) {
    free_json_str(json->keys + i);
  }
  i = 0;
  for (;i < json->size; i++) {
    free_json_any(json->vals + i);
  }
  free(json);
}

struct json_any * new_json_str(size_t size, char * bytes) {
  struct json_any * any = malloc(sizeof(struct json_any));
  struct json_str * str = malloc(sizeof(struct json_str));
  any->type = JSON_STR_TYPE;

  str->size = size;
  str->bytes = bytes;
  any->data.str = str;

  return any;
}

void free_json_str(struct json_str * json) {

}

struct json_any * new_json_num(double value) {
  struct json_any * any = malloc(sizeof(struct json_any));
  struct json_num * num = malloc(sizeof(struct json_num));
  any->type = JSON_NUM_TYPE;

  num->value = value;
  any->data.num = num;

  return any;
}

void free_json_num(struct json_num * json) {
  free(json);
}
