json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));
    
   if (value == 0)
      return 0;
   
   json_builder_value * temp = (json_builder_value *)value;
   temp->is_builder_value = 1;
   
   temp->type = json_integer;
   temp->u.integer = integer;

   return value;
}