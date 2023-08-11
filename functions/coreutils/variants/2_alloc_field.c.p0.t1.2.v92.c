alloc_field (int f, const char *c)
{
  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];

  if((field_data[f].used))
     return;

  if (c)
    columns[ncolumns - 1]->caption = c;
  
  field_data[f].used = true;   
}