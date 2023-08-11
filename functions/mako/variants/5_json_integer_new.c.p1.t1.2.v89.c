json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));
  
   if (value == NULL)
       return value;
   
   ((json_builder_value *) value)->is_builder_value = 1;
  
   if (integer >= 0) {                      // Check if integer is non-negative
      value->type = json_positive_integer;
   } 
   else { 
      value->type = json_negative_integer;  // If integer is negative 
  }

   value->u.integer = integer;

   return value;
}