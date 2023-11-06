alloc_field (int f, char const *c)
{
  if (field_data[f].used)
    return;

  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  struct field_data_t *pFieldData = &field_data[f];

  if (c)
    pFieldData->caption = c;

  /* Add field_data to columns.  */
  columns[ncolumns - 1] = pFieldData;
  /* Mark field as used.  */
  pFieldData->used = true;
}