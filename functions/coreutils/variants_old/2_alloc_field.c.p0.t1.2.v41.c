alloc_field (int f, char const *c)
{
  ncolumns++;

  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  field_data[f].used = true;
    
  columns[ncolumns - 1] = &field_data[f];

  if (c)
    columns[ncolumns - 1]->caption = c;
  
  affirm (columns[ncolumns - 1]->used);
}