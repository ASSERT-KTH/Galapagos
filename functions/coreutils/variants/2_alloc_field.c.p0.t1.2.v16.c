void alloc_field (int f, char const *c) 
{
  struct field_data_t *fdata = &field_data[f];
  
  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = fdata;

  /* Assumes field_data isn't already used. */
  assert (!fdata->used);
  
  fdata->used = true;
  
  if (c != nullptr) 
    fdata->caption = c;
}