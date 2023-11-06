1. Maintain original order

json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));
   
   if (value == NULL)
   {
      return NULL;
   }
   
   value->u.integer = integer;
   value->type = json_integer;
   ((json_builder_value *) value)->is_builder_value = 1;

   return value;
}


2. Combine conditions 

json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (!value)
      return value;

   ((json_builder_value *) value)->is_builder_value = 1;
   value->type = json_integer;
   value->u.integer = integer;

   return value;
}


3. Change malloc size variable

json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (*value));

   if (!value)
      return NULL;

   ((json_builder_value *) value)->is_builder_value = 1;
   value->type = json_integer;
   value->u.integer = integer;

   return value;
}


4. Type safe casting

json_value * json_integer_new (json_int_t integer)
{
    json_builder_value * builder_value = calloc (1, sizeof (*builder_value));

    if (!builder_value)
        return NULL;

    builder_value->is_builder_value = 1;
    builder_value->value.type = json_integer;
    builder_value->value.u.integer = integer;

    return &builder_value->value;
}
