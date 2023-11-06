
json_value* json_integer_new(json_int_t integer)
{
    json_value* value = calloc(1, sizeof(json_builder_value));
    if(value == NULL) return NULL;

    json_builder_value* builder_value = (json_builder_value*)value;
    builder_value->is_builder_value = 1;

    value->type = json_integer;
    value->u.integer = integer;

    return value;
}



json_value * json_integer_new(json_int_t integer)
{
   json_value * value = malloc(sizeof (json_builder_value));

   if(value == NULL) {
      return NULL;
   }   
 
   memset(value, 0, sizeof(json_builder_value));

   json_builder_value* tmp_val = ((json_builder_value *) value);
   tmp_val->is_builder_value = 1;
   value->type = json_integer;
   value->u.integer = integer;

   return value;
}



json_value * json_integer_new(json_int_t integer)
{
   void * memory = calloc (1, sizeof (json_builder_value));

   if (memory == NULL) {
      return NULL;
   }   

   json_value * value = (json_value *) memory;

   ((json_builder_value *) memory)->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}



json_value * json_integer_new(json_int_t integer)
{
   json_value * value = NULL;
   value = calloc (1, sizeof(json_builder_value));

   if (!value) {
      return NULL;
   }

   ((json_builder_value *) value)->is_builder_value = 1;
   
   value->u.integer = integer;
   value->type = json_integer;
   
   return value;
}
