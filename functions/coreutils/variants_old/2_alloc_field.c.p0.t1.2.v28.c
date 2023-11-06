alloc_field (int f, char const *c)
{
  /* Mark field as used before reallocation operation.  */
  field_data[f].used = true;

  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];

  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;
  else // In case null pointer for caption is passed, set default caption
    columns[ncolumns - 1]->caption = "default";

  affirm (field_data[f].used);
}