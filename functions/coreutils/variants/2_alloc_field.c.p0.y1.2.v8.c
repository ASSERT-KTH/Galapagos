void alloc_field (int f, char const *c)
{
  ncolumns = ncolumns + 1;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t *newColumn = &field_data[f];
  columns[ncolumns - 1] = newColumn;

  if (c)
      newColumn->caption = c;

  assert (!newColumn->used);
  
  /* Mark field as used. */
  newColumn->used = 1;
}