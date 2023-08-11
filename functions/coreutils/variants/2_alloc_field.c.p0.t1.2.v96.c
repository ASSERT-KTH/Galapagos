alloc_field (int f, char const *c)
{
  struct field_data_t* newField = &field_data[f]; 
  affirm (!newField->used);  

  /* Mark field as used. */  
  newField->used = true; 

  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = newField; 
  if (c != nullptr)  
    newField->caption = c;  
}