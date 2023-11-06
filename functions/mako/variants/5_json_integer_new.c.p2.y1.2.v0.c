json_value * json_integer_new (json_int_t integer)
{
    json_value * value;
    json_builder_value * new_value = calloc (1, sizeof(*new_value));
    value = (json_value *)new_value;
    
    if (!new_value)
    {
       return NULL;
    }
    else
    {
       new_value->is_builder_value = 1;
       value->type = json_integer;
       value->u.integer = integer;
    }
    
    return value;
}