json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (value == NULL)
     return value;

   json_builder_value* context = (json_builder_value *)value;
   context->is_builder_value = 1;

   context->type = json_integer;
   context->u.integer = integer;

   return value;
}