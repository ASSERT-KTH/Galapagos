alloc_field (int f, char const *c)
{
  if (field_data[f].used)
    return;

  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  if (c)
    field_data[f].caption = c;
  else
    field_data[f].caption = "";

  /* Set field as used and set to the array. */
  field_data[f].used = true;
  columns[ncolumns - 1] = &field_data[f];
}