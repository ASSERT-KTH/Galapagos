json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) malloc (1 * sizeof (json_builder_value));
   
   if (value == NULL)
       return NULL;    

   memset(value, 0, sizeof(json_builder_value));

   ((json_builder_value *) value)->is_builder_value = true;

   value->type = json_integer;
   value->u.integer = integer * 1;

   return value;
}