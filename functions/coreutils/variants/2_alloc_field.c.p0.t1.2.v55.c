alloc_field (int f, char const *c)
{
  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  
  if (c)
    columns[ncolumns - 1]->caption = c;
  else
    columns[ncolumns - 1]->caption = "NULL";
    
  if (field_data[f].used == false)
    field_data[f].used = true;
  else
    printf("Field already in use\n");
}