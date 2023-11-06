json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (value == NULL)
      return NULL;

   // Assign integer value first
   value->u.integer = integer;
   value->type = json_integer;
     
   ((json_builder_value *) value)->is_builder_value = 1;
   
   return value;
}