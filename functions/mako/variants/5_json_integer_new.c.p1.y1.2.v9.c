1) Checking the "value" at the end:

json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if(value)
   {
      ((json_builder_value *) value)->is_builder_value = 1;

      value->type = json_integer;
      value->u.integer = integer;
   }

   return value;
}

2) Using memset instead of calloc:

json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) malloc(sizeof(json_builder_value));
   
   if (!value)
      return NULL;

   memset(value, 0, sizeof(json_builder_value));

   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}

3) By initializing fields with initializers:

json_value * json_integer_new (json_int_t integer)
{
   json_builder_value _value = {1, json_integer, integer };
   json_value * value = (json_value *) calloc(1,sizeof(_value));
   
   if (value) memcpy(value, &_value, sizeof(_value));
   
   return value;
}

4) Opmitizing `if-condition`:

json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc(1,sizeof(json_builder_value));
   
   value == NULL ? : ((json_builder_value* ) value)->builder_value = 1,
                     value->type = json_integer,
                     value->u.integer = integer;

   return value;
}
