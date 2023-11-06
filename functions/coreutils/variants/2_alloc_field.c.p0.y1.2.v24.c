void alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t *new_column = &field_data[f];
  columns[ncolumns - 1] = new_column;

  if (c)
    new_column->caption = c;

  if (new_column->used == false)
    new_column->used = true;
}