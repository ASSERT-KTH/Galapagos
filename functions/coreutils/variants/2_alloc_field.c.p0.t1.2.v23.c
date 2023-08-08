//Program Variation:
alloc_field (int f, char const *c)
{

  columns = xnrealloc (columns, ncolumns++, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  
 
  if (c)
    columns[ncolumns - 1]->caption = c;

  if(!field_data[f].used)
  {
     field_data[f].used = true;
  }  

}
