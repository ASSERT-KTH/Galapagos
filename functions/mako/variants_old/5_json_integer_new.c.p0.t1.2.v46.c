json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));
   
   if (value == NULL)
      return NULL;
   
   ((json_builder_value *) value)->is_builder_value = true;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}