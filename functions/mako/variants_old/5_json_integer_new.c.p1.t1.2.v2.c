json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof(json_builder_value));
   json_builder_value * b_value;
   
   if (!value)
      return NULL;
   
   b_value = (json_builder_value *) value;

   b_value->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   assert(value->type == json_integer && value->u.integer == integer && b_value->is_builder_value);

   return value;
}