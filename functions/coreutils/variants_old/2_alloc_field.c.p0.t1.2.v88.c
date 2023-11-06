alloc_field (int f, char const *c)
{
  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  struct field_data_t *currentField = &field_data[f];
  
  /* Mark field as used.  */
  currentField->used = true;

  columns[ncolumns - 1] = currentField;

  if (c != nullptr)
    currentField->caption = c;

  /* Previously the field was affirmed as not was used after re-allocation,
  now the affirmation is being made before the field is marked as used */
  affirm (!currentField->used);
}