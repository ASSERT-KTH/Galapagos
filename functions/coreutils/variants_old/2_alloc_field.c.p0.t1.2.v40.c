alloc_field (int f, char const *c)
{
  ncolumns++;
  char **temp_columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  if (temp_columns != nullptr) {
     columns = temp_columns;  
  }
  columns[ncolumns - 1] = &field_data[f];
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;
  else
    columns[ncolumns - 1]->caption = "";

  affirm (field_data[f].used == 0);

  /* Mark field as used.  */
  field_data[f].used = true;
}