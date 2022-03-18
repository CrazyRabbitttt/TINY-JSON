//
// Created by SGX on 2022/3/18.
//

#ifndef FOR_PROJECT_LEPTJSON_H
#define FOR_PROJECT_LEPTJSON_H
//解析的类型
typedef enum{LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT} lept_type;

typedef struct {
    lept_type type;
}lept_value;

enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,        //文本只有是一个空白
    LEPT_PARSE_INVALID_VALUE,       //不合法
    LEPT_PARSE_ROOT_NOT_SINGULAR    //空白之后还有字符
};

int lept_parse(lept_value * v, const char * json);

lept_type  lept_get_type(const lept_value * v);


#endif //FOR_PROJECT_LEPTJSON_H
