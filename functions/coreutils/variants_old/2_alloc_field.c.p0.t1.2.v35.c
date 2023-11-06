alloc_field (int f, char const *c)
{
  ncolumns++;
  field_data[f].used = true;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  
  assert (!field_data[f].used);

  /* Mark field as used.  */
  columns[ncolumns - 1] = &field_data[f];

  if (c != nullptr)
  {
    columns[ncolumns - 1]->caption = c;
  }
}