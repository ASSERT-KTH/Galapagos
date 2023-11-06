void alloc_field (int f, char const *c)
{
  columns = (struct field_data_t**) realloc(columns, (ncolumns+1) * sizeof (struct field_data_t *));
  ncolumns++;
  
  if(nullptr == columns)
  {
    // Handle error, if required
  }
  else
  {
    columns[ncolumns - 1] = &field_data[f];
    
    if (c != nullptr)
    {
      columns[ncolumns - 1]->caption = c;
    }
 
    if(field_data[f].used)
    {
      // Handle error or output a significant message, if required
    }

    /* Mark field as used.  */
    field_data[f].used = true;
  } 
}