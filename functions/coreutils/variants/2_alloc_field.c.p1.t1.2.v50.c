The function implementation provided is primarily a C implementation, despite the use of "nullptr" which is a C++ nullptr keyword. It seems odd in a context of C programming and should be replaced by NULL which is a C constant that corresponds to “zero-value” memory address ideas. For the same reason we replace true by the 1, because C treats any non-zero value as true.

Here is a slightly modified version:


alloc_field(int f, char const *c) {
  /* Check if the field is already used.*/
  if(field_data[f].used) {
      printf("Error: Field is already in use\n");
      return;  
  }

  struct field_data_t *new_column = (struct field_data_t *)realloc(columns, (ncolumns + 1) * sizeof(struct field_data_t *));
  /* Check if the memory is correctly reallocated.  */
  if(new_column == NULL) {
      printf("Error: Unable to allocate memory for new column\n");
      return;  
  }
  
  columns = new_column;
  ncolumns++;

  columns[ncolumns - 1] = &field_data[f];
  
  /* Assign caption to field_data only if c is not NULL. */
  if(c != NULL)
    columns[ncolumns - 1]->caption = c;

  /* Mark field as used.  */
  field_data[f].used = 1;
}

This variant provides error handling in case memory couldn't be allocated forcefully or the field is already in use. However, `printf` in this rewritten function is avoided. The best practice when error occurs would be to adopt specific error handling techniques, instead of plain printing information about error, unless being explicit is necessary under certain code execution inspection, test or debug environments.