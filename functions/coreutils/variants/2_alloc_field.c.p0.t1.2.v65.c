alloc_field (int f, const char *c)
{
  affirm (field_data[f].used == false);
  
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  if (c)
    columns[ncolumns - 1]->caption = strdup(c);

  // Mark field as used
  field_data[f].used = true;
}