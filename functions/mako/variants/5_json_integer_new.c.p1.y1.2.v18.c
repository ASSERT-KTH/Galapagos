1. Using malloc instead of calloc:


json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) malloc (sizeof (json_builder_value));

   if (!value)
      return NULL;

   memset(value, 0, sizeof (json_builder_value));
   
   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}


2. Changing the order of the checks:


json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   value->type = json_integer;
   value->u.integer = integer;

   if (!value)
      return NULL;
   
   ((json_builder_value *) value)->is_builder_value = 1;

   return value;
}


3. Using ternary operator instead of if statement:


json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   value ? ((json_builder_value *) value)->is_builder_value = 1 : NULL;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}


4. Changing the type and assignment order:


json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (!value)
      return NULL;

   value->u.integer = integer;
   value->type = json_integer;
   
   ((json_builder_value *) value)->is_builder_value = 1;

   return value;
}
