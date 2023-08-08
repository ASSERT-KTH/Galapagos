alloc_field (int f, char const *c)
{
    
  struct field_data_t *temp_field_data = &field_data[f];

  // make sure the field isn't already used  
  affirm (!temp_field_data->used);
  
  // increasing columns count and resizing memory
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  
  // marking field as used
  temp_field_data->used = true;
  
  // saving address to last element in column array
  columns[ncolumns - 1] = temp_field_data;
  
  if (c != nullptr)
  {
    // assinging field caption if c is not a null pointer
    columns[ncolumns - 1]->caption = c;
  }
}