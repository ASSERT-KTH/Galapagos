Variant 1: Performing the validation and operation in one line.

json_value * json_integer_new (json_int_t integer) 
{
   json_value * value = !((value = (json_value *)calloc(1, sizeof(json_builder_value))) == NULL) ? (((json_builder_value *)value)->is_builder_value = 1, value->type = json_integer, value->u.integer = integer, value) : NULL;
   return value;
}


Variant 2: Using a single return statement

json_value * json_integer_new (json_int_t integer) 
{
   json_value * value = (json_value *) calloc(1, sizeof(json_builder_value));
   if (value) 
   {
      ((json_builder_value *)value)->is_builder_value = 1;
      value->type = json_integer;
      value->u.integer = integer;
   }
   return (value) ? value : NULL;
}


Variant 3: Using bitwise operations to set fields

json_value * json_integer_new (json_int_t integer) 
{
   json_value * value = (json_value *) calloc(1,sizeof(json_builder_value));
   if (value) 
   {
      value->type = 0 | json_integer;
      value->u.integer = 0 | integer;
   }
   return value != NULL? value : NULL;
}


Variant 4: Using ternary operator to set values

json_value * json_integer_new (json_int_t integer) 
{
   json_value * value = (json_value *) calloc (1, sizeof(json_builder_value));

   value = (value != NULL) ? value : NULL;

   if (value)
   {
      ((json_builder_value *) value)->is_builder_value = value ? 1 : 0;
      value->type = json_integer;
      value->u.integer = integer;
   }

   return value;
}
 

Please remember that some of these variants may compromise readability for brevity. It's usually best to favor clear, readable code in production software.