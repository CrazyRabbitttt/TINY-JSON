//
// Created by 邵桂鑫 on 2022/3/20.
//

#ifndef JSON1_LEPTJSON_H
#define JSON1_LEPTJSON_H

#include <stddef.h> /*include size_t*/

//因为我们在设置string之前需要检查v的type， 因此进行初始化
#define  lept_init(v) do{(v) -> type == LEPT_NULL; }while (0)

typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;

typedef struct {
    //一个值不可能同时是数字或者是字符串， 使用union进行存储
    union {
       struct {char * s; size_t  len; } s;      //string
       double n;                                //number
    } u;

    lept_type type;
}lept_value;

enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,
    LEPT_PARSE_INVALID_VALUE,
    LEPT_PARSE_ROOT_NOT_SINGULAR,
    LEPT_PARSE_NUMBER_TOO_BIG,
    LEPT_PARSE_MISS_QUOTATION_MARK,
    LEPT_PARSE_INVALID_STRING_ESCAPE,
    LEPT_PARSE_INVALID_STRING_CHAR
};

#define lept_init(v) do{(v) -> type = LEPT_NULL;}while (0)

int lept_parse(lept_value* v, const char* json);
void lept_free(lept_value * v);     //  清空原先v中进行分配的内存

#define lept_set_null(v) lept_free(v)

//the api : get & set
lept_type lept_get_type(const lept_value* v);

void lept_set_number(lept_value * v, double  n);
double lept_get_number(const lept_value* v);

int lept_get_boolean(const lept_value * v);
void lept_set_boolean(lept_value * v, int b);

void lept_set_string(lept_value * v, const char *s, size_t len);
const char * lept_get_string(const lept_value * v);

size_t  lept_get_string_length(const lept_value * v);




#endif //JSON1_LEPTJSON_H
