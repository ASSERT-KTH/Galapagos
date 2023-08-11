alloc_field (int f, char const *c)
{
  /* Check if field is already used before further processing. */
  if(field_data[f].used) return;

  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;

  /* Setting up column with appropriate field data. */
  columns[ncolumns - 1] = &field_data[f];

  /* Mark field as used. */
  field_data[f].used = true;
}
