alloc_field (int f, char const *c)
{
  /* Check if field is already used */
  if(field_data[f].used) return; 

  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];

  /* Check if caption is not null and assign it to the last cell. */
  if (c)
    columns[ncolumns - 1]->caption = c;
  else
    columns[ncolumns - 1]->caption = ""; 

  /* Mark field as used.  */
  field_data[f].used = true;
}