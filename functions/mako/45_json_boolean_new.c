json_value * json_boolean_new (int b)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (!value)
      return NULL;

   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_boolean;
   value->u.boolean = b;

   return value;
}