alloc_field (int f, char const *c)
{
  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  
  if (field_data[f].used)
      return;
   
  columns[ncolumns - 1] = &field_data[f];
  
  if (c != nullptr)
  {
    columns[ncolumns - 1]->caption = c;
  }
  
 /* Mark field as used.  */
  field_data[f].used = true;  
}