json_value * json_array_push (json_value * array, json_value * value)
{
   assert (array->type == json_array);

   if (!builderize (array) || !builderize (value))
      return NULL;

   if (((json_builder_value *) array)->additional_length_allocated > 0)
   {
      -- ((json_builder_value *) array)->additional_length_allocated;
   }
   else
   {
      json_value ** values_new = (json_value **) realloc
            (array->u.array.values, sizeof (json_value *) * (array->u.array.length + 1));

      if (!values_new)
         return NULL;

      array->u.array.values = values_new;
   }

   array->u.array.values [array->u.array.length] = value;
   ++ array->u.array.length;

   value->parent = array;

   return value;
}