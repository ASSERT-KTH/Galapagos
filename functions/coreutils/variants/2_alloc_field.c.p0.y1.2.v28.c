void alloc_field (int f, char const* c)
{  
  ncolumns = ncolumns + 1;

  field_data_t **temp = realloc(columns, ncolumns * sizeof(struct field_data_t *));
   
  if (temp == NULL)
  {  
    exit(EXIT_FAILURE);  
  }
  else
  {
    columns = temp;  
  }
  
  columns[ncolumns - 1] = &field_data[f];
   
  if (field_data[f].used)
  {
    printf("Field is already used.");
    exit(EXIT_FAILURE);
  }
    
  /* Mark field as used.  */
  field_data[f].used = true;

  if (c)
  {
    columns[ncolumns - 1]->caption = c;
  }
}