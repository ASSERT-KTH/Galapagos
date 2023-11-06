json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) malloc (sizeof (json_builder_value));
   
   // Handle dynamic memory allocation failure.
   if (!value)
   {  
      fprintf(stderr, "Failed to allocate memory.");
      return NULL;
   }

   memset(value, 0, sizeof(json_builder_value));

   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}