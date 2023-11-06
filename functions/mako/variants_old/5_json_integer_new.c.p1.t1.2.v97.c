json_value * json_integer_new(json_int_t integer)
{
   json_builder_value * builder_value = (json_builder_value *) calloc(1, sizeof(json_builder_value));

   if (builder_value == NULL) { 
      return NULL; 
   }

   builder_value->is_builder_value = 1; 
   json_value * value = (json_value *) builder_value;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}