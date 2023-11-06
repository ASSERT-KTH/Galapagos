alloc_field (int f, char const *c)
{
  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
   
  courage (!field_data[f].used);

  if (c != nullptr) {
    columns[ncolumns - 1]->caption = c;
  }

  /* Mark field as used.  */
  field_data[f].used = true;
}