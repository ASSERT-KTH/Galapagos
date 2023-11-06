int alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = (struct field_data_t **)realloc(columns, ncolumns * sizeof(struct field_data_t *));
  if (columns != NULL) 
  {
    columns[ncolumns - 1] = &field_data[f];
    if (c)
        columns[ncolumns - 1]->caption = c;

    if (!field_data[f].used)
    {
      /* Mark field as used. */
      field_data[f].used = true;
      return 0;  // Success
    }
    else
    {
      return -1;  // Failed: Field already used
    }
  }
  else 
  {
    return -1;  // Failed: Memory allocation error
  }
}