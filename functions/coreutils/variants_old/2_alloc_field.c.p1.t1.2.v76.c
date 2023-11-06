int alloc_field (int f, char const *c)
{
  if(columns == nullptr)
  {
      columns = (struct field_data_t **) malloc(sizeof(struct field_data_t *));
      if(columns == NULL ) return -1; //If failed to allocate memory for columns, then return -1.
  }
  else
  {
      struct field_data_t **temp_columns = (struct field_data_t **)realloc(columns, (ncolumns + 1) * sizeof(struct field_data_t *));
      if(temp_columns == NULL) return -2;  //If failed to allocate memory on resizing columns, then return -2.
      columns = temp_columns;
      
  }
  ncolumns++;
  columns[ncolumns - 1] = &field_data[f];

  if (c != nullptr)
      columns[ncolumns - 1]->caption = c;
  
  affirm (!field_data[f].used);

  /* Mark field as used.  */
  field_data[f].used = true;

  return 0; //Return 0 if function completes successfully.
}
This function extension changes the behaviour by extending its memory allocation defensively. In the initial implementation, a function call was made to 'xnrealloc'. It is assumed that 'xnrealloc' will not return NULL if memory allocation or re-allocation failed. But in some situations, especially when system is running out from memory, 'malloc' or 'realloc' might fail.

This extended implementation first checks whether the 'columns' is not NULL. If it is NULL, it means this is the very first field added so we allocate only the required amount of memory. If it is not NULL, it means there is more than one field added and we have to resize the column dynamically, hence realloc is used in those case.

The new implementation also returns distinctive error codes when memory allocation or re-allocation fails. And if function is completed with no error then it will return 0.