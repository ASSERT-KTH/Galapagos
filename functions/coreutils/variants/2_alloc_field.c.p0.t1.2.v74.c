alloc_field (int f, char const *c)
{
  ncolumns++;
  struct field_data_t **tcolumns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  if (!tcolumns)
    return;
  columns = tcolumns;

  columns[ncolumns - 1] = &field_data[f];

  if (c) {
    columns[ncolumns - 1]->caption = c;
  } else {
    columns[ncolumns - 1]->caption = NULL;
  }

  assert (!field_data[f].used);

  /* Mark field as used.  */
  field_data[f].used = true;
}