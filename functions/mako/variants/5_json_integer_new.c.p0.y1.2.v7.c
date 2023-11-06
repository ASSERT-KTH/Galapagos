json_value * json_integer_new (json_int_t integer)
{
   json_value * value = malloc(sizeof(json_builder_value));

   if (value == NULL) {
      return NULL;
   }

   memset