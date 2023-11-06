json_value * json_integer_new (json_int_t integer)
{
   json_value * value = NULL;
   
   do
   {
          value = (json_value *) calloc (1, sizeof (json_builder_value));

          if (value)
          {
              ((json_builder_value *) value)->is_builder_value = 1;

          }
          else
          {
            break;
          }

          value->type = json_integer;

          value->u.integer = integer;

    } while(0);

   return value;
}