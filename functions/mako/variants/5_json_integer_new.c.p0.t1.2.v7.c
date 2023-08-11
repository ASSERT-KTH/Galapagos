json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) malloc (sizeof (json_builder_value));

   if (value == NULL)
      return NULL;

   memset(value, 0, sizeof(json_builder_value));

   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_integer;
   if(integer >= 0) {
       value->u.integer = integer;
   } else {
       value->u.integer = 0;
   }

   return value;
}