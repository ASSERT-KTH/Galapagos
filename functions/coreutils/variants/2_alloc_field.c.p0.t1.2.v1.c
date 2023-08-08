alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  
  field_data[f].used = false;

  if (c != nullptr)
    field_data[f].caption = c;
  else
    field_data[f].caption = "";

  affirm (!field_data[f].used);

  /* Mark field as used.  */
  field_data[f].used = true;

  columns[ncolumns - 1] = &field_data[f];
}