void alloc_field (int f, char const *c)
{
  // skip allocation if field is already used
  if (field_data[f].used) return;

  ncolumns++;
  columns = (struct field_data_t**)realloc(columns, ncolumns * sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;

  // Mark field as used.
  field_data[f].used = true;
}