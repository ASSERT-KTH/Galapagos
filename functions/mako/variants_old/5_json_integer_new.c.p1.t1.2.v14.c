json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));
   json_builder_value * casted_value = NULL;   /* line added */

   if (!value)
      return NULL;

   casted_value = (json_builder_value *) value; /* line updated */

   casted_value->is_builder_value = 1;   /* line updated */

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}