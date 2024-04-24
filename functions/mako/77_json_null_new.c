json_value * json_null_new (void)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (!value)
      return NULL;

   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_null;

   return value;
}