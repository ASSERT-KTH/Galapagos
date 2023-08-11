json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));
   json_builder_value * builder;

   if (!value)
      return NULL;
   else
      builder = (json_builder_value *) value;
      
   builder->is_builder_value = 1;
   value->type = json_integer;
   ((json_integer_value *)value)->u.value = integer;

   return value;
}