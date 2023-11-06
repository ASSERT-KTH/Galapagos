json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) malloc (sizeof (json_builder_value));

   if( value == NULL)
   {
      return NULL;

   } else {

      ((json_builder_value *) value)->is_builder_value = 1;
      memset(value+1, 0, sizeof(json_value) - 1);

      value->type = json_integer;
      value->u.integer = integer;

      return value;
   }      
}