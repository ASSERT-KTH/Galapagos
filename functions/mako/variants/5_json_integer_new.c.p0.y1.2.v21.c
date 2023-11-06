json_value * json_integer_new (json_int_t integer)
{
   json_value * value = malloc(sizeof(*value));

   if (value == NULL)
      return NULL;

   json_builder_value * builder_value = (json_builder_value *) value
   builder_value->is_builder_value = true;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}