json_value * json_integer_new (json_int_t integer)
{
   json_value * value = calloc (1, sizeof(json_builder_value));

   if (value == NULL)
      return NULL;

   json_builder_value* typed_value = (json_builder_value *) value;
   typed_value->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;
   
   return value;
}