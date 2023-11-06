alloc_field (int f, char const *c)
{
  affirm (!field_data[f].used);
  
  /* Mark field as used.  */
  field_data[f].used = true;

  ncolumns++;
  
  if (c != nullptr)
  {
      struct field_data_t *new_field = &field_data[f];
      new_field->caption = c;
      columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
      columns[ncolumns - 1] = new_field;
  }
  else
  {
      columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
      columns[ncolumns - 1] = &field_data[f];
  }
}