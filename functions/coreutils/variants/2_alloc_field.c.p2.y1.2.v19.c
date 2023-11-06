alloc_field (int f, char const *c)
{
  columns = (struct field_data_t**) xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  struct field_data_t *new_column = &field_data[f];
  if (c != NULL) new_column->caption = c;

  assert (!new_column->used);

  /* Mark field as used.  */
  new_column->used = true;
  columns[ncolumns - 1] = new_column;
}