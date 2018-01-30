#ifndef _PARSE_H
#define _PARSE_H

#include "json.h"
#include "token.h"

struct json_any * parse(struct tokens * tokens);

#endif
