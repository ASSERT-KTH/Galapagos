json_value * json_integer_new (json_int_t integer)
{
   if integer < 0 
     return NULL;

   json_value * value;
   value = (json_value *) malloc (sizeof (json_builder_value));

   if (!value){
       free(value);
       return NULL;
   }

   json_builder_value * builder_value = (json_builder_value *) value;

   builder_value->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}