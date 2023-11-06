void alloc_field (int f, char const *c)
{
  struct field_data_t **temp_columns = (struct field_data_t**)realloc(columns, (ncolumns+1)*sizeof(struct field_data_t*));
  if (temp_columns == nullptr) {
    exit(EXIT_FAILURE);
  }
  columns = temp_columns;
  columns[ncolumns] = &field_data[f];
  ncolumns++;

  if (c != nullptr)
  {
    columns[ncolumns - 1]->caption = c;
  }
  
  assert (field_data[f].used == false);

  /* Mark field as used.  */
  field_data[f].used = true;
}