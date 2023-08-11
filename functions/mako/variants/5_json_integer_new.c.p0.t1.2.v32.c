json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) malloc (sizeof (json_builder_value));

   if (value == NULL)
       return NULL;

   ((json_builder_value *) value)->is_builder_value = 1;

   if (integer < 0)
       value->u.integer = 0;
   else
       value->u.integer = integer;

   value->type = json_integer; 

   return value;
}