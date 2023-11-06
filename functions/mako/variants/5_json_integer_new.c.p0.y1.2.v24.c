json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) malloc(sizeof (json_builder_value));
   memset( value, 0, sizeof(json_builder_value));

   if (!value)
        return NULL;

   json_builder_value* builder = (json_builder_value* )value;
   builder->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   return value;  
}