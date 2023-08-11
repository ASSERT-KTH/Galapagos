json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (!value)
   {
      fprintf(stderr, "Failed to allocate memory for json_value.");
      return NULL;
   }

   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_integer;
   
   if(integer < 0)
   {
       printf("Negative integer was parsed to json_integer. Stored as is.");
   }
   value->u.integer = integer;
   
   return value;
}