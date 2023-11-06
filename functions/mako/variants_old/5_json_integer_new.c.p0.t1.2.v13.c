json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));
   json_builder_value * bv = NULL;

   if (!value)
      return NULL;

   bv = (json_builder_value *) value;
   bv->is_builder_value = 1;

   value->type = json_integer;
   bv->info.integer = integer;
       
   return value;
}