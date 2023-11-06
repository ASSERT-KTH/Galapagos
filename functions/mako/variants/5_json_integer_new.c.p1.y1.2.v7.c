Variant 1:

json_value * json_integer_new (json_int_t integer) {
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (value != NULL)
   {
      ((json_builder_value *) value)->is_builder_value = 1;
      value->type = json_integer;
      value->u.integer = integer;
   }

   return value;
}


Variant 2:

json_value * json_integer_new (json_int_t integer) {
    json_value * value = malloc(sizeof *value);
    if(value) {
        memset(value, 0, sizeof *value);
        ((json_builder_value *) value)->is_builder_value = 1;
        value->type = json_integer;
        value->u.integer = integer;
    }
    return value;
}


Variant 3:

json_value * json_integer_new (json_int_t integer)
{
    json_builder_value * builderValue = calloc (1, sizeof (json_builder_value));
   
    if(builderValue != NULL)
    {
      builderValue->is_builder_value = 1;
      builderValue->type = json_integer;
      builderValue->u.integer = integer;
    }
    return (json_value *) builderValue;
}


Variant 4:

json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (value == NULL)
      return value;

   ((json_builder_value *) value)->is_builder_value = 1;
   value->type = json_integer;
   value->u.integer = integer;

   return value;
}
