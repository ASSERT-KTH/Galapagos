alloc_field (int f, char const *c)
{
  ncolumns++;
  struct field_data_t **temporary = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  if (temporary == nullptr)
    return;
    
  columns = temporary;
  columns[ncolumns - 1] = &field_data[f];

  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;
  else  
    columns[ncolumns - 1]->caption = 'Default';

  if (!field_data[f].used)
      field_data[f].used = true;
  else
      return;
}
