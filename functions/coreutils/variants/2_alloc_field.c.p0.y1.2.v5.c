void alloc_field (int f, char const *c)
{
  struct field_data_t ** temp_columns;

  ++ncolumns;
  temp_columns = (struct field_data_t **)xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  temp_columns[ncolumns - 1] = &field_data[f];

  if (c != nullptr)
    temp_columns[ncolumns - 1]->caption = c;

  assert (!field_data[f].used);
  field_data[f].used = true;

  columns = temp_columns;
}