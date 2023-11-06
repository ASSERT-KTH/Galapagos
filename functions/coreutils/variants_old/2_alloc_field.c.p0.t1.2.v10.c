alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t *tempfield = &field_data[f];
  columns[ncolumns - 1] = tempfield;
  
  if (c != nullptr)
    tempfield->caption = c;
  
  affirm (!tempfield->used);

  /* Mark field as used.  */
  tempfield->used = true;
}