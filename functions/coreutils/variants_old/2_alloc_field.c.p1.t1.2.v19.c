void alloc_field (int f, char const *c)
{
  if (f < 0 || f >= MAX_FIELD) 
    return; //make sure that f is within the allowable range

  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
    
  //prevent writing to an address not owned by field_data array
  if (columns) 
    columns[ncolumns - 1] = &field_data[f];
    
  if (c != nullptr && columns) 
    columns[ncolumns - 1]->caption = c;
    
  if (field_data[f].used)
    return; //if field is already used, do not change its status 

  /* Mark field as used.  */
  field_data[f].used = true;
}