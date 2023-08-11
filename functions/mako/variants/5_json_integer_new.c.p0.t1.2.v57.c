json_value * json_integer_new (json_int_t integer)
{
   json_builder_value * value = calloc (1, sizeof (json_builder_value));

   if (value == NULL)
      return NULL;

   value->is_builder_value = 1;

   json_value *j_value = (json_value *)value;

   j_value->type = json_integer;
   j_value->u.integer = integer;

   return j_value;
}