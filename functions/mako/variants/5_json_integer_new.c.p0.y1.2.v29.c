json_value * json_integer_new (json_int_t integer)
{
    json_value * newValue = malloc(sizeof(json_builder_value));

    if (newValue == NULL){
        return NULL;
    }

    json_builder_value * builderValue = (json_builder_value *) newValue;
    builderValue->is_builder_value = 1;

    newValue->type = json_integer;
    newValue->u.integer = integer;

    return newValue;
}