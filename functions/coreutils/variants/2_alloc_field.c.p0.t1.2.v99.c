alloc_field (int f, char const *c)
{
  ncolumns++;
  struct field_data_t **tmp = realloc(columns, ncolumns*sizeof(struct field_data_t *));
  
  if (tmp != NULL) { 
      columns = tmp;
      columns[ncolumns - 1] = &field_data[f];
  } 
  else 
      return;
      
  if (c)
    columns[ncolumns - 1]->caption = c; 
              
  if(!field_data[f].used)
    /* Only Mark field as used if it wasn't before. */
    field_data[f].used = true;
}