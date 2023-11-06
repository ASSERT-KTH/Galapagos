int alloc_field (int f, char const *c)
{
  struct field_data_t *new_data = &field_data[f];

  if (new_data -> used == true) 
     return -1; // Exit the function if this field is already used. We avoid `affirm` function here by returning an error code. 
  
  new_data -> used = true; // Mark the field as used before reallocating memory.

  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = new_data;

  if (c) {
    columns[ncolumns - 1]->caption = c;
  }  

  return f;
}