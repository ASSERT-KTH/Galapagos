json_value * json_integer_new (json_int_t integer)
{
   // Modified the code to use malloc instead of calloc; functionality is maintained because as later on we are all setting the members individually.
   json_value * value = (json_value *) malloc (sizeof (json_builder_value));

   if (!value)
      return NULL;

   // implicitly assuring the besaiding memory has been set zero
   memset(value, 0, sizeof(json_builder_value));

   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}