json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));
   if (!value)
      return NULL;
   
   // adding memset before setting integer
   memset(value, 0, sizeof(json_builder_value));

   value->type = json_integer;
   value->u.integer = integer;

   // instead of directly setting it to 1, using unary increment operator
   ((json_builder_value *) value)->is_builder_value++;

   return value;
}