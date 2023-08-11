void alloc_field (int f, char const *c)
{
  if (f < 0 || f >= sizeof(field_data) / sizeof(*field_data))
    return;

  if (field_data[f].used)
    return;

  columns = (struct field_data_t **)realloc(columns, (ncolumns+1) * sizeof(struct field_data_t *));
  if (columns == nullptr)
    exit(EXIT_FAILURE);
  
  ncolumns++;
  columns[ncolumns - 1] = &field_data[f];

  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;

  /* Mark field as used. After doing all the operations to avoid inconsistent state in case of any runtime error */
  field_data[f].used = true;
}
The above variant of the original alloc_field() have a few changes but maintains its original functionality.
The function checks if the input 'f' is a valid index for the array 'field_data' to avoid array index out of bound errors and prevent accessing illegal memory.

Also, it checks if the field is already in use before allocating it to avert assigning to a used field.  

In addition though, C's realloc function doesn't mandate an immediate exit upon NULL (an error scenario). So we would also now be checking realloc's returned result down to NULL & exiting via EXIT_FAILURE, thus adding an error scenario which could prevent the program from crashing.

Finally, it updates 'field_data'[f].used also signals whether the process failed or completed successfully, therefore the updated field occurs last.
