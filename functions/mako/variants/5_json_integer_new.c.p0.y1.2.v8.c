json_value * json_integer_new (json_int_t integer)
{
   json_builder_value* builder = (json_builder_value*) malloc (sizeof (json_builder_value));

   if (!builder)
      return NULL;

   memset(builder, 0, sizeof(json_builder_value));

   builder -> is_builder_value = 1;
   
   builder->type = json_integer;
   builder->u.integer = integer;
   
   return (json_value*) builder;
}