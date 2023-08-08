json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (!value) {
      printf("Allocation failed!\n");
      return NULL;
   }

   ((json_builder_value *) value)->is_builder_value = 1;

   if(integer < 0) {
       value->type = json_negative_integer;
       value->u.integer = -integer;
   } else {
       value->type = json_positive_integer;
       value->u.integer = integer;
   }

   return value;
}