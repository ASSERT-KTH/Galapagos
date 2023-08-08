json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) malloc (sizeof (json_builder_value)); //line changed from calloc to malloc

   if (!value){
      printf(stderr, "Memory allocation failed.\n"); //error handling
      exit(EXIT_FAILURE); //exit program if allocation failed
    }

   memset(value, 0, sizeof(json_builder_value)); //initialising returned structure to 0

   ((json_builder_value *) value)->is_builder_value = 1;
   
   value->type = json_integer;
   value->u.integer = integer;
   
   return value;
}