json_value * json_integer_new_alt (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));
   
   if (value == NULL)
      return value;
     
   json_builder_value * builder = (json_builder_value *)value;

   builder->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}