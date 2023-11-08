json_value * json_integer_new (json_int_t integer)
{
   json_builder_value * value = (json_builder_value *) malloc (sizeof (json_builder_value));

   if (value == NULL)
      return NULL;

   memset(value, 0, sizeof(json_builder_value));

   value->is_builder_value = 1;

   value->basic_value.type = json_integer;
   value->basic_value.u.integer = integer;

   return (json_value *)value;
}