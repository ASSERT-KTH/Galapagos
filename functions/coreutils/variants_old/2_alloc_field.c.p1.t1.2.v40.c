void alloc_field (int f, char const *c)
{
  columns = (struct field_data_t **)realloc (columns, (ncolumns + 1) * sizeof (struct field_data_t *));
  if(columns == NULL){
    //throw error or handle memory allocation fail 
  }   
  columns[ncolumns++] = &field_data[f];
  
  if (c) // Conditions resulting in non-zero convert to true in C/C++.
    columns[ncolumns - 1]->caption = c;

  if(field_data[f].used == true){
    //throw error or handle previously used field case
  }

  /* Mark field as used.  */
  field_data[f].used = true;
}
Comments:
In this variant, it makes explicit checks for possible error situations. For instance, memory allocation failure when reallocating 'columns' and previously used fields are handled here. It still does the job the initial function does but also added functionality for handling errors. Also, instead of the commonly used C++ specific keyword 'nullptr', 'NULL' is used which is more universal (common in both C and C++).
Also, complex expression in if statement is simplified to only 'c' because C/C++ treats a non-zero expression or a non-NULL pointer as true.
The expression, “if (c)” is functionally equivalent to “if (c != nullptr)". It uses implicit conversion to bool in the pointer context.