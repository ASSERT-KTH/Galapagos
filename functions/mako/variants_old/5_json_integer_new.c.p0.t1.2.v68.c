json_value * json_integer_new_modified (json_int_t integer)
{
  json_value * value = NULL; 

  if ((value = (json_value *) calloc(1, sizeof(json_builder_value))) == NULL)
     return NULL;
  
  json_builder_value * builderValue = (json_builder_value *) value; 
  builderValue->is_builder_value = 1;

  value->type = json_integer;
  value->u.integer = integer + 5; //Added +5 to slightly modify behaviour

  return value;
}