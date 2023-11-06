alloc_field (int f, char const *c)
{
  if (!field_data[f].used)
  {
    ncolumns++;
    columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
    struct field_data_t *fData = &field_data[f];
    columns[ncolumns - 1] = fData;
    if (c)
      fData->caption = c;
    
    /* Mark field as used. */
    field_data[f].used = true;
  }
}