alloc_field (int f, char const *c)
{
  ncolumns = ncolumns + 1;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t* newFieldData = &field_data[f];
  columns[ncolumns - 1] = newFieldData;
  if (c)
    newFieldData->caption = c;

  affirm (!newFieldData->used);

  /* Mark field as used.  */
  newFieldData->used = true;
}