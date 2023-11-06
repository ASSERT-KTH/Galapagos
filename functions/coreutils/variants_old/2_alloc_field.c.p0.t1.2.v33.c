alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t* new_column = &field_data[f];
  columns[ncolumns - 1] = new_column;
  if (c != nullptr)
    new_column->caption = c;

  assert (!field_data[f].used);
  
  /* Mark field as used. */
  new_column->used = true;  
}