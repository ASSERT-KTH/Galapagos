json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) malloc(sizeof (json_builder_value));

   if (!value || integer < 0)
      return NULL;

   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = abs(integer);

   return value;
}