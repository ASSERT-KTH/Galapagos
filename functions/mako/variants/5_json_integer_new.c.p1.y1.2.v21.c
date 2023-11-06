1) Using malloc() instead of calloc():

json_value *json_integer_new(json_int_t integer) 
{
    json_value *value = (json_value *) malloc(sizeof(json_builder_value));
  
    if (!value)
        return NULL;

    memset(value, 0, sizeof(json_builder_value));

    ((json_builder_value *) value)->is_builder_value = 1;

    value->type = json_integer;
    value->u.integer = integer;

    return value;
}


2) Repositioning assignment lines:

json_value *json_integer_new(json_int_t integer) 
{
    json_value *value = (json_value *) calloc(1, sizeof(json_builder_value));

    if (!value)
        return NULL;

    value->type = json_integer;
    value->u.integer = integer;

    ((json_builder_value *) value)->is_builder_value = 1;

    return value;
}


3) Using the 'sizeof' function on typed memory:

json_value *json_integer_new(json_int_t integer)
{
    json_value *value = (json_value *) calloc(1, sizeof(*value));

    if (!value)
        return NULL;

    ((json_builder_value *) value)->is_builder_value = 1;

    value->type = json_integer;
    value->u.integer = integer;

    return value;
}


4) assigning value directly inside the structure:

json_value *json_integer_new(json_int_t integer)
{   
    json_value *value = (json_value *) calloc(1, sizeof(json_builder_value));

    if (!value) 
        return NULL;

    ((json_builder_value *) value)->is_builder_value = 1;
    ((json_builder_value *) value)->value->type = json_integer;
    ((json_builder_value *) value)->value->u.integer = integer;

    return value;
}
