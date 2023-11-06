1. We can start with reversing the condition for simplicity:


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


2. C doesn't require the brackets around the single-statement if condition, so we can take those out:


json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (value)
      ((json_builder_value *) value)->is_builder_value = 1; 
   
   if (value)
      value->type = json_integer; 
   
   if (value)
      value->u.integer = integer;

   return value;
}


3. We can bring the assignment operation inside the condition to make the steps more explicit:


json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (value)
      ((json_builder_value *) value)->is_builder_value = value == NULL ? 0 : 1; 
   
   if (value)
      value->type = value == NULL ? 0 : json_integer; 
   
   if (value)
      value->u.integer = value == NULL ? 0 : integer;

   return value;
}


4. The `calloc` function used in the division occupies less space than a ternary operator assignment which could make the code faster:


json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));
   json_builder_value * builder_value = (json_builder_value *) value;

   if (value)
      builder_value->is_builder_value = value == NULL ? 0 : 1; 
   
   if (value)
      value->type = value == NULL ? 0 : json_integer; 
   
   if (value)
      value->u.integer = value == NULL ? 0 : integer;

   return value;
}
