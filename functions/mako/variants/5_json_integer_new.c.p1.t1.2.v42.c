json_value * json_integer_new (json_int_t integer)
{
   int allocation_successful = 1;
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));
   
   if (value == NULL)
    {
      allocation_successful = 0;
      value = (json_value *) malloc (sizeof(json_builder_value));
    }

   if (!value || !allocation_successful)
      return NULL;

   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   if (!allocation_successful)
   {
       // clean up memory if calloc failed but malloc succeeded
       free(value);
       return NULL;
   }

   return value;
}