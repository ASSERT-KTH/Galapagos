alloc_field (int f, char const *c)
{
  int colIndex;
  
  ncolumns = ncolumns + 1;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  
  colIndex = ncolumns - 1;
  columns[colIndex] = &field_data[f];
  if (c)
    columns[colIndex]->caption = c;
  else
    columns[colIndex]->caption = "";

  if(!field_data[f].used)
  {  
    /* Mark field as used.  */
    field_data[f].used = true;
 }  
}
