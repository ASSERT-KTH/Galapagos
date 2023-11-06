1. Separating allocation and initialization:


json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc (1, sizeof (json_builder_value));

   if (value == NULL)
      return NULL;

   json_builder_value * builderValue = (json_builder_value *) value;
   builderValue->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}


2. Using memset instead of calloc:


#include<string.h>

json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) malloc(sizeof(json_builder_value));

   if (!value)
      return NULL;

   memset(value, 0, sizeof(json_builder_value));

   ((json_builder_value *) value)->is_builder_value = 1;

   value->type = json_integer;
   value->u.integer = integer;

   return value;
}


3. Using early return:


json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc(1, sizeof(json_builder_value));

   if (!value)
      return value;

   ((json_builder_value *) value)->is_builder_value = 1;
   value->type = json_integer;
   value->u.integer = integer;

   return value;
}


4. Inlining creation of json_builder_value:


json_value * json_integer_new (json_int_t integer)
{
   json_builder_value * builderValue = (json_builder_value *) calloc(1, sizeof(json_builder_value));
   if(!builderValue)
      return NULL;
   
   builderValue->is_builder_value = 1;

   json_value * value = (json_value *) builderValue;

   value->type = json_integer;
   value->u.integer = integer;
   
   return value;
}


5. Using designated initializers (only with C99 or later):


json_value * json_integer_new (json_int_t integer)
{
   json_value * value = (json_value *) calloc(1, sizeof(json_builder_value));
   
   if (!value)
      return NULL;

   *value = (json_value) {
       .type = json_integer,
       .u.integer = integer,
   };
   
   ((json_builder_value *) value)->is_builder_value = 1;

   return value;
}
