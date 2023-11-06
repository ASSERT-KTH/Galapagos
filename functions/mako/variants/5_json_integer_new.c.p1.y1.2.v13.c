Variant 1:

json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) malloc (sizeof (json_builder_value));

   if (value)
   {
       memset(value, 0, sizeof(json_builder_value));
       ((json_builder_value *) value)->is_builder_value = 1;
       value->type = json_integer;
       value->u.integer = integer;
   }

   return value;
}


Variant 2:

json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_builder_value *) malloc (sizeof (json_builder_value));

   if (value)
   {
       value->type = json_integer;
       value->u.integer = integer;
       
       if(value != NULL)
           ((json_builder_value *) value)->is_builder_value = 1;

   }

   return value;
}


Variant 3:

json_value * json_integer_new (json_int_t integer)
{
   json_builder_value * builderValue = (json_builder_value *) calloc (1, sizeof (json_builder_value));
   
   if (!builderValue)
      return NULL;
   
   builderValue->is_builder_value = 1;

   json_value * value = (json_value *) builderValue;
   value->type = json_integer;
   value->u.integer = integer;

   return value;
}


Variant 4:

json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (value)
    {
        ((json_builder_value *) value)->is_builder_value = 1;
        value->type = json_integer;
        value->u.integer = (integer != 0) ? integer : 0;
    }

   return value;
}
