void alloc_field (int f, char const *c)
{
  struct field_data_t **temp_columns = (struct field_data_t **) realloc (columns, (ncolumns + 1) * sizeof (struct field_data_t *));

  if (temp_columns != nullptr) {
    columns = temp_columns;
    columns[ncolumns] = &field_data[f];
  
    if (c != NULL)
      columns[ncolumns]->caption = c;
  
    assert(!field_data[f].used);

    /* Mark field as used.  */
    field_data[f].used = true;
  
    ncolumns++;
  }
}