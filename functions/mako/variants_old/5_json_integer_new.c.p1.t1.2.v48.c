json_value * json_integer_new (json_int_t integer)
{
   json_value * value;

   // Allocate memory using malloc instead of calloc
   value = (json_value *)malloc(sizeof(json_builder_value));
   
   if(value == NULL)
   {
      return NULL;
   }

   // Initialize the allocated memory to 0
   memset(value, 0, sizeof(json_builder_value)); 

   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}