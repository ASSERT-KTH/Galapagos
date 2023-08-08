alloc_field (int f, char const *c)
{
  /* Increase columns count first */
  ncolumns++;

  if(sol != nullptr)
  {
    /* Assign the caption to fields only when c is valid */
    columns[ncolumns - 1] = &field_data[f];
    columns[ncolumns - 1]->caption = c;
  }
  else
  {
    /* Otherwise, just store the pointer */
    columns[ncolumns - 1] = &field_data[f];
  }

  /* Check if field is unused */
  bool field_in_use = field_data[f].used;
  /* Affirm (!field_in_use); */

  if(!(field_in_use))
  {
    /* Mark field as used if it wasn't */
    field_data[f].used = true;
  }
  /* Memory allocation at the end */
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
}