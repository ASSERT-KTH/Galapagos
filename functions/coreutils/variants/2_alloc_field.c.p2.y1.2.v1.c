alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = (struct field_data_t **)xnrealloc (columns, ncolumns, sizeof(struct field_data_t *));
  
  /* Mark field as used.  */
  field_data[f].used = true;
  
  columns[ncolumns - 1] = &field_data[f];
  if (c != (char const *)0) 
    columns[ncolumns - 1]->caption = xstrdup (c);

  assert (!field_data[f].used);
}