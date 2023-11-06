alloc_field (int f, char const *c)
{
  assert(!field_data[f].used);

  /* Mark field as used. */
  field_data[f].used = true;

  ncolumns++;
  columns = (struct field_data_t **) realloc(columns, ncolumns * sizeof(struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];

  if (c)
  {
    columns[ncolumns -  1]->caption = c;
  }
}