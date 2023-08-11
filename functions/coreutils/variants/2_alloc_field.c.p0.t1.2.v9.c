alloc_field (int f, char const *c)
{
  if(f < 0) // Negative indices are not allowed
    return;

  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));

  if(c == nullptr)
    columns[ncolumns - 1] = &field_data[f];
  else
  {
    columns[ncolumns - 1] = &field_data[f];
    columns[ncolumns - 1]->caption = c;
  }
  
  if(field_data[f].used) // Already in use
    return;
  
  /* Mark field as used.  */
  field_data[f].used = true;  
}