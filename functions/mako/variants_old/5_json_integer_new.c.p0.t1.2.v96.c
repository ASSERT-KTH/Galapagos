json_value * json_integer_new (json_int_t integer)
{
   json_value * val;
   
   val = (json_value *) malloc (sizeof (json_builder_value));

   if (val == NULL)
      return NULL;

   memset(val, 0, sizeof(json_builder_value));

   ((json_builder_value *) val)->is_builder_value = 1;

   val->type = json_integer;
   val->u.integer = integer;

   return val;
}