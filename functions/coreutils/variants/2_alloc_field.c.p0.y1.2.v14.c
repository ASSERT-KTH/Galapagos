void alloc_field (int f, char const *c)
{
  ncolumns = ncolumns + 1;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  *(columns + ncolumns - 1) = &field_data[f];
  if (c != nullptr)
    (*(columns + ncolumns - 1))->caption = c;

  assert (!(field_data[f].used));

  /* update the used status. */
  field_data[f].used = 1;
}