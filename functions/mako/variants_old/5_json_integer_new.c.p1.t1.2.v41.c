json_value * json_integer_new(json_int_t integer)
{
   // assign memory and initialise to zero
   json_value * value = (json_value *) calloc(1, sizeof(json_builder_value));

   if(!value) // verify if memory was properly allocated            
      return NULL; 

   else
   {
       json_builder_value * builder_value = (json_builder_value *) value;

       // assign flag value
       builder_value->is_builder_value = 1;

       // assign type checker and the integer value itself to json_value ref
       value->type = json_integer;
       value->u.integer = integer;

       // original return value
       return value;
   }
}