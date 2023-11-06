void alloc_field (int f, char const *c)
{
  struct field_data_t** temp_col = (struct field_data_t**) realloc(columns, (ncolumns + 1) * sizeof(struct field_data_t *));
  if (temp_col != NULL) {  
    columns = temp_col;
    ncolumns++;
    columns[ncolumns - 1] = &field_data[f];
    
    if (c)
      columns[ncolumns - 1]->caption = c;
    
    if (field_data[f].used == false){
        /* Mark field as used.  */
        field_data[f].used = true;
    }
  }
}