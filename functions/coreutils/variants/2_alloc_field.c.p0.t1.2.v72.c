alloc_field (int f, char const *c)
{
  if (c != nullptr)
  {
    ncolumns++;
    columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
    columns[ncolumns - 1] = &field_data[f];
    columns[ncolumns - 1]->caption = c;

    affirm (!field_data[f].used);

    /* Mark field as used.  */
    field_data[f].used = true;
  }
}