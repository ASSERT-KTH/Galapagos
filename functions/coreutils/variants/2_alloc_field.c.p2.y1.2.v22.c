void alloc_field (int f, char const *c)
{
  struct field_data_t *newFieldData;
  
  ncolumns++;
  columns = (struct field_data_t **) realloc (columns, ncolumns * sizeof (struct field_data_t *));
  newFieldData = &field_data[f];
  columns[ncolumns - 1] = newFieldData;

  assert (newFieldData->used == false);
  newFieldData->used = true;
  
  if (c)
    newFieldData->caption = strdup(c);
}