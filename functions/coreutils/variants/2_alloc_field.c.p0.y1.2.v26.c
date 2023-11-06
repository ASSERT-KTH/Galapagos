void alloc_field (int f, char const *c)
{
  struct field_data_t** temp;
  ncolumns += 1;      
  temp = (struct field_data_t**) realloc(columns, ncolumns * sizeof(struct field_data_t *));
  
  //Checking if memory successfully re-allocated
  if(temp != NULL) 
  {
    columns = temp;
    columns[ncolumns - 1] = &field_data[f]; // adding the new element
    
    if (c)
       columns[ncolumns - 1]->caption = c;
    
    assert(field_data[f].used == false); // ensuring the field is not used
   
  
    // marking the field as used
    field_data[f].used = true;   
  }
  else
  {
    exit(EXIT_FAILURE); // quit if realloc() fails
  }
}