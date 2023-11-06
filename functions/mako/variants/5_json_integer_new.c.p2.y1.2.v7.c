json_value * json_integer_new (json_int_t integer)
{
   // Allocate memory and check for failure
   json_value * value = (json_value *) malloc (sizeof (json_builder_value));
   if (!value)
     return NULL;

   // Zero-out the new memory
   memset(value, 0, sizeof(json_builder_value));

   ((json_builder_value *) value)->is_builder_value = 1;

   // Direct definition of variable fields  
   value->type = json_integer;
   value->u.integer = integer;

   return value;
}