json_value * json_integer_new (json_int_t integer)
{
   json_value * value;
   
   value = malloc(sizeof(json_value)); 
   
   if (value == NULL)
   {
       free(value);
       return (json_value*) 0;
   }

   ((json_builder_value *) value)->is_builder_value = 1;
   
   value->type = json_integer;
   value->u.integer = integer;
   
   return value;
}