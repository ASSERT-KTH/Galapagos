alloc_field (int f, char const *c)
{
  if (!field_data[f].used)
  {
    ncolumns++;
    struct field_data_t** temp = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
    if (temp)
    {
      columns = temp;
      columns[ncolumns - 1] = &field_data[f];
      if (c != nullptr)
        columns[ncolumns - 1]->caption = c;
  
      /* Mark field as used.  */
      field_data[f].used = true;
    }
  
    affirm (!field_data[f].used);
  }
}