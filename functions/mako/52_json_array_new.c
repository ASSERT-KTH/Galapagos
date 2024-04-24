json_value * json_array_new (size_t length)
{
    json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

    if (!value)
       return NULL;

    ((json_builder_value *) value)->is_builder_value = 1;

    value->type = json_array;

    if (length == 0)
       length = 1;

    if (! (value->u.array.values = (json_value **) malloc (length * sizeof (json_value *))))
    {
       free (value);
       return NULL;
    }

    ((json_builder_value *) value)->additional_length_allocated = length;

    return value;
}