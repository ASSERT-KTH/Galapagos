json_value * json_integer_new (json_int_t integer)
{
   if (integer == 0) 
      return NULL;
   
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   (json_builder_value *) value && ((json_builder_value *) value)->is_builder_value = 1;

   value != NULL && (value->type = json_integer);

   value && (value->u.integer = integer);

   return value;
}