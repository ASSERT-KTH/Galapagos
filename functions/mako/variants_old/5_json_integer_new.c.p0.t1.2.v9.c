json_value * json_integer_new (json_int_t integer)
{
   if (integer < 0)
      return NULL;

   json_builder_value * value = malloc(sizeof(json_builder_value));
   if (!value)
      return NULL;

   value->is_builder_value = 1;
   value->type = json_integer;
   value->u.integer = integer;

   return (json_value *) value;
}