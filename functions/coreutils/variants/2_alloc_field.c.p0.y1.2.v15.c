void alloc_field (int f, char const *c)
{
  ncolumns = ncolumns + 1;
  columns = (struct field_data_t*)realloc(columns, ncolumns * sizeof(struct field_data_t *));
  struct field_data_t *currentField =  &field_data[f];
  columns[ncolumns - 1] = currentField;

  if (c != nullptr)
    (columns[ncolumns - 1])->caption = c;

  assert(field_data[f].used == false);

  /* Mark field as used.  */
  currentField->used = true;
}