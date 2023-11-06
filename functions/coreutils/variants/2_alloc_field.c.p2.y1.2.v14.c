alloc_field (int f, char const *c)
{
  ncolumns++;

  // Reallocate space with added space for an additional element
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  
  // If provided a valid string
  if (c)
  {
    // Allocate a new struct, assign it the given field_data[f] value
    // and assign its caption to the string
    struct field_data_t *newField = &field_data[f];
    newField->caption = c;
    columns[ncolumns - 1] = newField;
  }
  else
  {
    // If not provided with a valid string, no caption assignment
    columns[ncolumns - 1]= &field_data[f];
  }

  // Ensure field wasn't used before
  assert(!field_data[f].used);

  // Mark field as used
  field_data[f].used = true;
}