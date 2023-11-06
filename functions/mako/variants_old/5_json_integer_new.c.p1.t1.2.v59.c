Here’s a variant of the function that maintains its original functionality but changes its behavior by error-checking the calloc function:


json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));
   
   if (value == NULL)
   {
	   fprintf(stderr, "Memory allocation failed!\n");
	   exit(1);
   }
   
   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}

In this version of the function, if calloc fails to allocate the required memory it'll not just simply return a NULL, however it will report an error and terminates the program. This way it incorporates some basic error-checking about the possible outcomes of certain operations. Please note that this is a trivial error-handling mechanism, in a real-life application it might be way more complex. For example, just terminating the program when calloc fails isn't generally recommended because it doesn't allow the caller a graceful way to recover from the memory error. In certain cases, this behavior can be incredibly inconvenient. In the original form this wasn't handled in the function at all.