json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) malloc (sizeof (json_builder_value));
   if (value == NULL)
     return value;

   memset(value, 0, sizeof(json_builder_value));

   json_builder_value * jbv_val = (json_builder_value *) value;

   /* Setting properties of json_builder_value */
   jbv_val->is_builder_value = 1;

    /* Setting properties of json_value */
   value->type = json_integer;
   value->u.integer = integer;

   return value;
}