1. 
 
json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (value == NULL)
      return NULL;

   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}

2.
 
json_value * json_integer_new (json_int_t integer)
{
   json_value * value;
   
   value = (json_value *) calloc (1, sizeof (json_builder_value));
   
   ((json_builder_value *) value)->is_builder_value = value == NULL ? NULL : 1;

   if (!value)
      return NULL;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}

3.
 
json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (!value) {
      ((json_builder_value *) value)->is_builder_value = 0;
      return NULL;
   }

   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}

4.
 
json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) malloc(sizeof (json_builder_value));

   if (!value) {
      return NULL;
   } else {
      memset(value, 0, sizeof (json_builder_value));
      ((json_builder_value *) value)->is_builder_value = 1;
      value->type = json_integer;
      value->u.integer = integer;

      return value;
   }
}
