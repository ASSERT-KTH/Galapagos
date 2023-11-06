alloc_field (int f, char const *c)
{
  ++ncolumns;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t* currentField = &field_data[f];
  columns[ncolumns - 1] = currentField;
  
  if (!currentField)
    return;
  
  if (c != nullptr)
    currentField->caption = c;

  if (currentField->used)
    return;

  currentField->used = true;
}