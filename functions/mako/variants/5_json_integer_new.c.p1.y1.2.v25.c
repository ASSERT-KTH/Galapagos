Variant 1:

json_value * json_integer_new (json_int_t integer)
{
   json_value * value;
   
   value = (json_value *) calloc (1, sizeof (json_builder_value));
   
   if (value == NULL)
      return NULL;

   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}


Variant 2:

json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (value){
      
      ((json_builder_value *) value)->is_builder_value = 1;

      value->type = json_integer;
      value->u.integer = integer;

      return value;
   }else{
      return NULL;
   }
}


Variant 3:

json_value * json_integer_new (json_int_t integer)
{
   json_value * value = NULL;
   
   value = (json_value *) calloc (1, sizeof (json_builder_value));
   
   if (value != NULL)
   {
      ((json_builder_value *) value)->is_builder_value = 1;

      value->type = json_integer;
      value->u.integer = integer;

      return value;
   }

   return value;
}


Variant 4:

json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (value)
   {
      value->is_builder_element = 1;
      value->representation = json_bool_obj;
      
      ((json_builder_value *) value)->u.integer = integer;
      ((json_builder_value *) value)->type = json_integer;

      return value;
   }else{
      return NULL;
   }
}
