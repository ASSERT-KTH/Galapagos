json_value * json_integer_new (json_int_t integer)
{
   json_value * value;
   value = calloc (1, sizeof (json_builder_value));

   if (NULL == value)
      return NULL;

   value->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}