alloc_field (int f, char const *c)
{
  if (field_data[f].used)
    return;

  columns = xnrealloc (columns, ncolumns + 1, sizeof (struct field_data_t *));
  columns[ncolumns++] = &field_data[f];

  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;
  else
    columns[ncolumns - 1]->caption = "";

  /* Mark field as used.  */
  field_data[f].used = true;
}