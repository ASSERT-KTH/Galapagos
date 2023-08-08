int alloc_field (int f, char const *c)
{
  if (f < 0) return -1; // Error handling for negative input value of 'f'
  
  ncolumns++;
  struct field_data_t *tmp = realloc(columns, ncolumns * sizeof (struct field_data_t *));
  if (tmp == NULL) return -1; // Checking for unsuccessful allocation
    
  columns = tmp;
  columns[ncolumns - 1] = &field_data[f];

  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;

   //If the field is already used, return an error code, keeps the original logic of not allowing re-usage
  if(field_data[f].used) {
    return -1; 
  }

  /* Mark field as used.  */
  field_data[f].used = true;
  return 0; // For successful operation completion. Ensuring that the function's original functionality is maintained
}