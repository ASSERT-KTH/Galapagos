1. A version with early return:

json_value *json_integer_new(json_int_t integer) {
    json_value *value = (json_value *)calloc(1, sizeof(json_builder_value));
    if (!value)
        return NULL;

    json_builder_value *builder_value = (json_builder_value *)value;
    builder_value->is_builder_value = 1;
    builder_value->type = json_integer;
    builder_value->u.integer = integer;
  
    return builder_value;    
}


2. A less readable version with fewer lines of code:

json_value *json_integer_new(json_int_t integer) {
    json_value *value;
    if (!((value = (json_value *)calloc(1, sizeof(json_builder_value))))) return NULL;
  
    ((json_builder_value *)value)->is_builder_value = 1;
    value->type = json_integer;
    value->u.integer = integer;

    return value;
}


3. An explicitly typecasted version:

json_value *json_integer_new(json_int_t integer) {
    json_builder_value *value = NULL;
  
    value = (json_builder_value *)calloc(1, sizeof(json_builder_value));
    if (value == NULL) {
        return NULL;
    }

    value->is_builder_value = 1;
    ((json_value *)value)->type = json_integer;
    ((json_value *)value)->u.integer = integer;

    return (json_value *)value;
}


4. The "multiple points of exit" philosophical disagreement version:

json_value *json_integer_new(json_int_t integer) {
    json_builder_value *value = (json_builder_value *)calloc(1, sizeof(json_builder_value));

    if (value == NULL) {
        fprintf(stderr,"Allocation Failed.\n");
        exit(1);
    }

    value->is_builder_value = 1;
    ((json_value *)value)->type = json_integer;
    ((json_value *)value)->u.integer = integer;

    return (json_value *)value;
}

  
5. The ternary operator version with macro:

#define malloc_check(val) ((val) ? (val) : NULL)

json_value *json_integer_new(json_int_t integer) {
    json_value *value = (json_value *)calloc(1, sizeof(json_builder_value));
  
    void* ptr = malloc_check(value);
    if (ptr != NULL) {
        ((json_builder_value *)value)->is_builder_value = 1;
        value->type = json_integer;
        value->u.integer = integer;
    }

    return value;
}
