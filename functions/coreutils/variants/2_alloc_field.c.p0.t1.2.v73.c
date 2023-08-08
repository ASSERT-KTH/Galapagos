alloc_field (int f, char const *c)
{
  /* move this up */
  /* Mark field as used.  */
  field_data[f].used = 1;

  ncolumns++;  
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  if (c)
    columns[ncolumns - 1]->caption = c;

  affirm (!field_data[f].used);
  
  /* Moved this line up */
  /* field_data[f].used = true; */
}