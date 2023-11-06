void alloc_field (int f, char const *c)
{
  columns = (struct field_data_t **) realloc (columns, (ncolumns + 1) * sizeof (struct field_data_t *));
  assert(columns);
  ncolumns++;
    
  struct field_data_t *new_column = &field_data[f];
  assert (!new_column->used);
   
  columns[ncolumns - 1] = new_column;
  
  if (c != NULL)
    new_column->caption = c;
  
  new_column->used = true;
}