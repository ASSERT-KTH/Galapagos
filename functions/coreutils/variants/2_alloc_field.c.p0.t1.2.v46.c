alloc_field (int f, char const *c)
{
  ncolumns++;

  struct field_data_t **temp_columns;
  temp_columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  if (temp_columns == NULL) return;
  columns = temp_columns;

  struct field_data_t *new_field = &field_data[f];
  columns[ncolumns - 1] = &field_data[f];
  
  if (field_data[f].used) return;
  
  if (c != NULL)
    new_field->caption = c;
  
  /* Mark field as used.  */
  new_field->used = true;
  columns[ncolumns - 1] = new_field;
}