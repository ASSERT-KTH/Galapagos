json_value * json_integer_new(json_int_t integer)
{
   json_value * value = (json_value *) malloc (sizeof (json_builder_value));

   if (value)
   {
      ((json_builder_value *) value)->is_builder_value = 1;

      value->type = json_integer;
      value->u.integer = integer;

      /* Added error checking condition */
      if (value->type != json_integer || value->u.integer != integer)
      {
         free(value);
         value = NULL;
      }
   }

   // A memset(added in place of calloc used earlier in code
   ((size_t)integer > sizeof(json_builder_value))
      ? memset(value, 0, sizeof(json_builder_value)) 
      : memset(value, 0, (size_t)integer);
      
   return value;
}