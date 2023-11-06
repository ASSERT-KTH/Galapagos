Variant 1:

json_value * json_integer_new (json_int_t integer)
{
   json_value * value = NULL;

   if ((value = (json_value *) calloc (1, sizeof (json_builder_value))) == NULL)
      return NULL;

   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_integer;

   value->u.integer = integer;

   return value;
}


Variant 2:

json_value * json_integer_new (json_int_t integer)
{
   json_builder_value *value = calloc(1, sizeof(*value));
   
   if (value == NULL)
      return NULL;
   
   value->is_builder_value = 1;
   
   value->base_value.type = json_integer;
   value->base_value.u.integer = integer;
   
   return (json_value*)value;
}


Variant 3:

json_value *json_integer_new(json_int_t integer) 
{
  json_value *value = malloc(sizeof(json_builder_value));
  
  if (value == NULL) 
  {
    free(value);
    return NULL;
  }
  
  memset(value, 0, sizeof(json_builder_value));
  
  ((json_builder_value *)value)->is_builder_value = 1;
  
  value->type = json_integer;
  value->u.integer = integer;
  
  return value;
}


Variant 4:

json_value * json_integer_new (json_int_t integer)
{
   json_value  *value = (json_value *) calloc(1, sizeof(json_builder_value));
  
   if (value == NULL) 
   {
      return NULL;
   }

   json_builder_value *builder_value = (json_builder_value *)value;
   
   builder_value->is_builder_value = 1;

   builder_value->base_value.type = json_integer;
   
   builder_value->base_value.u.integer = integer;

   return (json_value *)builder_value;
}
