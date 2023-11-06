Variant 1:

json_value * json_integer_new (json_int_t integer) 
{
   json_value * value = NULL;
   
   value = (json_value *) calloc (1, sizeof (json_builder_value));
   if (!value)
      return value;

   value->type = json_integer;
   ((json_builder_value *) value)->is_builder_value = 1;
   value->u.integer = integer;

   return value;
}


Variant 2: 

json_value * json_integer_new (json_int_t integer) 
{
   json_value * value = (json_value *) malloc (sizeof (json_builder_value));
   
   memset(value, 0, sizeof(json_value));

   if (!value) 
      return NULL;

   ((json_builder_value *) value)->is_builder_value = 1;
   value->type = json_integer;
   value->u.integer = integer;

   return value;
}


Variant 3: 

json_value * json_integer_new (json_int_t integer) 
{
   json_value * value = calloc (1, sizeof (json_builder_value));

   if (value == NULL)
      return NULL;
   
   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}


Variant 4:

json_value * json_integer_new (json_int_t integer) 
{
   json_value * value = NULL;

   do
   {
      value = (json_value *) calloc (1, sizeof (json_builder_value));
      if(!value)
         break;

      ((json_builder_value *) value)->is_builder_value = 1;
      value->type = json_integer;
      value->u.integer = integer;

   } while(0);

   return value;
}
