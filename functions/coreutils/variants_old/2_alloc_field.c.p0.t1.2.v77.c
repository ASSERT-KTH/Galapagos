alloc_field (int f, const char *c)
{
  ncolumns++;
  struct field_data_t ** new_columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  if(new_columns != NULL) 
  {
    columns = new_columns;
    columns[ncolumns - 1] = &field_data[f];
    if (c)
      columns[ncolumns - 1]->caption = c;
    affirm (!field_data[f].used);

    /* Mark field as used.  */
    field_data[f].used = true;
  }
}