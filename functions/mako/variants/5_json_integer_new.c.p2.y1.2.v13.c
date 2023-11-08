json_value * json_integer_new (json_int_t integer)
{
   json_value * value = NULL;

   if ((value = (json_value *) calloc (1, sizeof (json_builder_value))) == NULL)
      return NULL;
   
   ((json_builder_value *) value)->is_builder_value = 1;
   
   value->type = json_integer;
   value->u.integer = integer;

   return value;
}