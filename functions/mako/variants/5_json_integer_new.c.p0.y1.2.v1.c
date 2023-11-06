json_value * json_integer_new (json_int_t integer)
{
    json_value * newValue;
    newValue = calloc (1, sizeof (json_builder_value));

    if (! newValue)
        return NULL;

    ((json_builder_value *) newValue)->is_builder_value = 1;
    newValue->type = json_integer;
    newValue->u.integer = integer;
    
    return newValue;
}