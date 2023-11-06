void alloc_field (int f, char const *c)
{
  // Check if the field is already used
  if(field_data[f].used)
    return;

  ncolumns++;
  columns = (struct field_data_t **)realloc(columns, ncolumns * sizeof(struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  
  // Only change caption if it isn't null
  if (c != nullptr) 
  {
    columns[ncolumns - 1]->caption = strdup(c);
  }

  // Validating that field_data is not used yet
  assert (!field_data[f].used);

  // Mark field as used
  field_data[f].used = true;
}
The above variant provides a precaution for when the provided field has already been used. Also, strdup is used to ensure a new copy of the string is made, which could prevent problems in case the original string is altered externally, though this may not be necessary depending on the program context.