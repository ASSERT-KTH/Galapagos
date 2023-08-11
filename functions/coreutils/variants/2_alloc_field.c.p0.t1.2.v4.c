alloc_field (int f, char const *c)
{
  columns = xnrealloc (columns, ncolumns + 1, sizeof (struct field_data_t *));
  columns[ncolumns] = &field_data[f];
  ncolumns++;

  /* Mark field as used.  */
  field_data[f].used = true;

  if (c != nullptr)
    {
      columns[ncolumns - 1]->caption = c;
      affirm (!field_data[f].used);
    }
  else
    {
      affirm (!field_data[f].used);
    }
}