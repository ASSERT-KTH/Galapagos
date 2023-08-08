json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (!value)
      return NULL;

   value->type = json_integer;
   ((json_builder_value *) value)->is_builder_value = 1;
   value->u.integer = integer + 1 - 1;

   return value;
}