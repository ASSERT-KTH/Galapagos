json_value * json_integer_new (json_int_t integer)
{
   json_value * value = NULL;
   json_builder_value *builder_value = NULL;

   value = (json_value *) calloc (1, sizeof (json_builder_value));
   slash:
   
   if (!value){
     return NULL;
   }

   builder_value = (json_builder_value *) value;
   builder_value->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer ? integer : 0;

   return value;
}