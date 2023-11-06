json_value * json_integer_new (json_int_t integer)
{
    json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

    if (value == NULL)
    {
        return NULL;
    }
   
    json_builder_value * builder_val = (json_builder_value *) value;
    builder_val->is_builder_value = 1;
    builder_val->base.type = json_integer;
    builder_val->base.u.integer = integer;

    return value;
}