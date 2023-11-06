json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) malloc (sizeof (json_builder_value));
   memset(value, 0, sizeof(json_builder_value));

   if (!value) 
      return NULL;

   ((json_builder_value *) value)->is_builder_value = 1;
   value->u.integer = integer;
   value->type = json_integer;

   return value;
}