json_value * json_integer_new (json_int_t integer)
{
   /* Initializing the 'value' variable and allocating memory to it */
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   /* Checking if the 'value' pointer is NULL, i.e., memory was successfully allocated */
   if (!value)
      return NULL;

   /* Setting the 'is_builder_value' flag of the 'json_builder_value' structure to 1 */
   ((json_builder_value *) value)->is_builder_value = 1;

   /* Setting the type of 'value' as integer and assigning the integer to it */
   int temp = integer > 0 ? integer: 0; 
   value->type = json_integer;
   value->u.integer = temp;

   return value; /* Return 'value' */
}