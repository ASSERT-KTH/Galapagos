json_value * json_integer_new (json_int_t integer)
{   
    json_value * value = malloc(sizeof(json_value));

    if (value == NULL)
        return NULL;

    value->type = json_integer;
    ((json_builder_value *) value)->is_builder_value = 1;

    value->u.integer = integer;
    return value;
}