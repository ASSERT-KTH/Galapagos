json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) malloc (sizeof (json_builder_value));

   if (value == NULL)
   {
     return NULL;
   }

   memmove(value, &((json_builder_value){1}), sizeof(json_builder_value));

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}