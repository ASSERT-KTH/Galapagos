alloc_field (int f, char const *c)
{
  /* Mark field as used.  */
  field_data[f].used = true;

  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  
  if (c)
    columns[ncolumns - 1]->caption = (char*)c;

  if(field_data[f].used != true) 
  {
    abort();
  }
}