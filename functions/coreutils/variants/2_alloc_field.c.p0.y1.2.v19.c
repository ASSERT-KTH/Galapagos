void alloc_field(int f, const char *c)
{
  ncolumns = ncolumns + 1;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));

  struct field_data_t*** p = &columns;
  *(*p + ncolumns - 1) = &field_data[f];

  if (c)
    (**p + ncolumns - 1)->caption = c;

  assert (!field_data[f].used);

  field_data[f].used = 1;
}