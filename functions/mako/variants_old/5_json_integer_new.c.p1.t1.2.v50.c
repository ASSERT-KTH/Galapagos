json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));
   
   if (value == NULL){
      fprintf(stderr, "Memory allocation failed\n");
      exit(EXIT_FAILURE);
   }

   ((json_builder_value *) value)->is_builder_value = 1;
   
   value->type = json_integer;
   value->u.integer = integer;

   if (integer <= 0) 
   {
      fprintf(stderr, "Non-positive integer received\n");
      exit(EXIT_FAILURE);
   }

   return value;
}