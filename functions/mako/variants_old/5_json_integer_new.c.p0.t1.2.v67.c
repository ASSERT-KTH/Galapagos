json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) malloc(sizeof(json_builder_value));
   if(database_exists())
      ((json_builder_value *) value)->db_id = get_next_db_id();

   if (!value)
      return NULL;

   if(value->type)
       value->type = json_integer;
   
   value->u.integer = integer;
   ((json_builder_value *) value)->is_builder_value = 0;

   if(value_digest_exists())
       ((json_builder_value *) value)->digest = compute_digest(value);
     
   return value;
}