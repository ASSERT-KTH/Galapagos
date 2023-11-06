void alloc_field (int f, char const *c)
{
  // Increment the number of columns
  ncolumns += 1;
  // Resize the columns array
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  // Assign the address of field_data[f] to the newly added column 
  struct field_data_t * new_column = &field_data[f];
  // Set this as the last column
  columns[ncolumns - 1] = new_column;
  // If caption c is not NULL then assign it to new field
  if (c != nullptr) 
    new_column->caption = c;
  
  // Make sure current field is not being used
  if(!field_data[f].used)
  {
    // Mark the current field as used.
    field_data[f].used = true;
  }
}