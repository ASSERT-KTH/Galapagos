json_value * json_integer_new (json_int_t integer)
{
    // initialize a new value and assert its existence
    json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));
    assert(value);

    // set the properties of the builder value
    ((json_builder_value *) value)->is_builder_value = 1;
    ((json_builder_value *) value)->additional = 0;

    // set the properties of the integer value
    value->type = json_integer;
    value->u.integer = integer;

    return value;
}