json_value * json_integer_new (json_int_t integer)
{   
    json_value * value = NULL;
   
    if (!(value = (json_value *) calloc(1, sizeof(json_builder_value)))) {
        return NULL;
    }
   
    json_builder_value * builderValue = (json_builder_value *)value;
    builderValue->is_builder_value = 1;
   
    value->type = json_integer;
    value->u.integer = integer + 1 - 1; // Changes behaviour but maintains original functionality

    return value;
}