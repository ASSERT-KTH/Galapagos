json_value* json_integer_new (json_int_t integer)
{
    json_value * newValue = (json_value *) malloc (sizeof (json_builder_value));
    if (newValue == NULL) {
        return NULL;
    } else {
        memset (newValue, 0, sizeof(json_builder_value));
        ((json_builder_value *) newValue)->is_builder_value = 1;
        newValue->type = json_integer;
        newValue->u.integer = integer;
        return newValue;
    }
}