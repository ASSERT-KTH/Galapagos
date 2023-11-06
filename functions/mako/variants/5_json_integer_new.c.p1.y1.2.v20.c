Variant 1:

json_value * json_integer_new (json_int_t integer)
{
   json_value * value = NULL;
   
   value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (value != NULL)
   {
      ((json_builder_value *) value)->is_builder_value = 1;

      value->type = json_integer;
      value->u.integer = integer;
   }

   return value;
}


Variant 2:
 
json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (value)
   {
      ((json_builder_value *) value)->is_builder_value = 1;
      value->type = json_integer;
      value->u.integer = integer; 
   }
   
   return value;
}


Variant 3:
 
json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (value == NULL)
       return NULL;
   else
   {
      ((json_builder_value *) value)->is_builder_value = 1;
      value->type = json_integer;
      value->u.integer = integer; 
   }

   return value;
}

Variant 4:

json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (!value)
      return NULL; 

   json_builder_value *builder_val = (json_builder_value *)value;
   builder_val->is_builder_value = 1;
   value->type = json_integer;
   value->u.integer = integer; 

   return value;
}
