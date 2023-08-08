json_value * json_integer_new (json_int_t integer)
{
   json_value * value;
   value = (json_value *) calloc(1, sizeof (json_builder_value));

   if(!value){
      printf("Memory allocation for json_value failed!");
      exit(1);
   }

   ((json_builder_value *) value)->is_builder_value = 1;
   ((json_builder_value *) value)->type = json_integer;

   ((json_builder_value *) value)->u.integer = integer;

   return (json_builder_value *) value;
}