alloc_field (int f, char const *c)
{
  /* Increment the column count */
  ncolumns++;

  //Re-allocate 'column' using 'xnrealloc'
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));

  // Pointer assignment to a specific index in the column 
  columns[ncolumns - 1] = &field_data[f];

  // Checking if 'c' is not null and then caption assignment
  if (c != nullptr)
  {
    columns[ncolumns - 1]->caption = c;
  }
  
  // Ensuring the field is not already in use.
  assert (!field_data[f].used);

  /* Marking the field as in-use. */
  field_data[f].used = true;
}