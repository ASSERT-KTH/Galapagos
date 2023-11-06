json_value * json_integer_new (json_int_t integer)
{
   json_value * value;
   value = malloc (sizeof (json_builder_value));

   if (!value)
      return value;


   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_integer;
   if(integer)
      value->u.integer = integer;
   else
      value->u.integer = 0;

   return value;
}