alloc_field (int f, char const *c)
{
  ncolumns++;
  struct field_data_t **temp_columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  if (temp_columns == nullptr)
  {
      // handle error
      --ncolumns;
      return;
  }

  columns = temp_columns;
  columns[ncolumns - 1] = &field_data[f];
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;
  
  if (field_data[f].used)
    return;
  
  /* Mark field as used.  */  
  field_data[f].used = true;
}