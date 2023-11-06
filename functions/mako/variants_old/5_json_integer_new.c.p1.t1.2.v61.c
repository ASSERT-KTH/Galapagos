json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));
  
   if (!value)
   {
      printf("Failed to allocate memory!\n");
      exit(0);
   }

   json_builder_value * building_value = (json_builder_value *)value;
   building_value->is_builder_value = 1;

   value->type = json_integer;

   /* Adding a basic conditionality check */
   if (integer < 0)
   {
      value->u.integer = -1 * integer; // Make it a positive integer
   }
   else
   {
      value->u.integer = integer;
   }   

   return value;
}