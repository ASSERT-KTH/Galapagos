alloc_field (int f, char const *c)
{
  ncolumns++;
  affirm (!field_data[f].used);
  
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  
  /* Mark field as used.  */
  field_data[f].used = true;
  
  columns[ncolumns - 1] = &field_data[f];
  
  if (c != 0)
    columns[ncolumns - 1]->caption = c;
}