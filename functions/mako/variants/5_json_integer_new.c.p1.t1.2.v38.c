json_value * json_integer_new (json_int_t integer) 
{
   // Allocated memory for json_value
   json_value * value = (json_value *) malloc (sizeof (json_builder_value));

   // Checking if memory allocation is successful
   if (value == NULL)
      return NULL;

   // Initializing the memory with zero.
   memset(value, 0, sizeof(json_builder_value));

   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}