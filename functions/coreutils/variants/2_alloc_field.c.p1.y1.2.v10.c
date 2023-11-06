Variant 1:

void alloc_field (int f, char const *c)
{
  struct field_data_t** temp = (struct field_data_t **)realloc (columns, ++ncolumns * sizeof (struct field_data_t *));
  columns = temp;
  struct field_data_t* newData = &field_data[f];
  columns[ncolumns - 1] = newData;
    
  if (c != NULL)
    newData->caption = c;
      
  assert (!newData->used);
  
  /* Mark field as used.  */
  newData->used = true;
}


Variant 2:

void alloc_field (int f, char const *c)
{
  columns = (struct field_data_t **)realloc (columns, ++ncolumns * sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  struct field_data_t* insertField = columns[ncolumns - 1];
    
  if (c != NULL)
  {
    insertField->caption = c;
  }
      
  assert(!field_data[f].used);
  
  /* Mark field as used.  */
  field_data[f].used = 1;
}


Variant 3:

void alloc_field (int f, char const *c)
{
  ++ncolumns;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t *fieldInstance = &field_data[f];
  columns[ncolumns - 1] = fieldInstance;
  if (c)
    fieldInstance->caption = c;
  
  assert (!fieldInstance->used);
  
  /* Mark field as used.  */
  fieldInstance->used = true;
}


Would be best to also look over the functionality to ensure the transformations have preserved its original functionality: memory allocation, imposing conditions, assertions and direct changes.