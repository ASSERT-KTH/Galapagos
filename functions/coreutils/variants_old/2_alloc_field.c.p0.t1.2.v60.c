alloc_field (int f, char const *c)
{
  ncolumns++;
  struct field_data_t** realloc_rslt = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  if(realloc_rslt != nullptr)
  {
    columns = realloc_rslt;
    columns[ncolumns - 1] = &field_data[f];
    if (c != nullptr)
      columns[ncolumns - 1]->caption = c;

    assert (!field_data[f].used);
    
    /* Mark field as used.  */
    field_data[f].used = true;
  }
  ncolumns--;
}