1.

json_value* json_integer_new(json_int_t integer)
{
    json_value* value = (json_value*) malloc(sizeof(json_builder_value));
    memset(value, 0, sizeof(json_builder_value));
  
    if (!value)
        return NULL;

    ((json_builder_value *)value)->is_builder_value = 1;
  
    value->type = json_integer;
    value->u.integer = integer;

    return value;
}


2.

json_value* json_integer_new(json_int_t integer)
{
    json_value * value;
    value = (json_value *) calloc (1, sizeof (json_builder_value));
    if(value == NULL)
    return NULL; 

    ((json_builder_value *) value)->is_builder_value = 1;

    value->type = json_integer;
    value->u.integer = integer;

    return value;
}


3.

json_value * json_integer_new (json_int_t integer)
{
   json_value* value = (json_value *) calloc (1, sizeof(json_builder_value));
   
   if (value != NULL)
   {
      ((json_builder_value *) value)->is_builder_value = 1;

      value->type = json_integer;
      value->u.integer = integer;
   }
   
   return value;
}


4.

json_value* json_integer_new(json_int_t integer)
{
   json_builder_value* builder_value = (json_builder_value *) calloc (1, sizeof (json_builder_value));

   if (!builder_value)
      return NULL;
   
   builder_value->is_builder_value = 1;
   
   json_value* value = (json_value*)builder_value;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}


5.

json_value * json_integer_new (json_int_t integer)
{
   json_builder_value* builder = (json_builder_value *) calloc (1, sizeof (json_builder_value));

   if (!builder)
      return NULL;

   builder->is_builder_value = 1;

   json_value* value = (json_value*)builder;
   value->type = json_integer;
   value->u.integer = integer;

   return value;
}
