alloc_field (int f, char const *c)
{
  affirm (!field_data[f].used);
  
  ncolumns++;
  
  struct field_data_t ** columns_temp = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  if(c != nullptr)
    field_data[f].caption = c;

  field_data[f].used = true;
  
  columns_temp[ncolumns - 1] = &field_data[f];
  columns = columns_temp;
}