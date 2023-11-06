json_value * json_integer_new (json_int_t integer)
{
   json_builder_value * builder_value = (json_builder_value *) malloc (sizeof (json_builder_value));
   if (!builder_value)
      return NULL;

   memset(builder_value, 0, sizeof(json_builder_value));

   builder_value->is_builder_value = 1;

   json_value * value = (json_value *) builder_value;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}