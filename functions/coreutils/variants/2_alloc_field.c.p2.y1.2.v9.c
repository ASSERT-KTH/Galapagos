void alloc_field (int f, char const *c)
{
  ncolumns = ncolumns + 1;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  int lastElementIndex = ncolumns - 1;
  columns[lastElementIndex] = &field_data[f];
  if (c)
    columns[lastElementIndex]->caption = c;
  
  assert (!field_data[f].used);
  
  /* Mark field as used.  */
  field_data[f].used = 1;
}