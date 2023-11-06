alloc_field (int f, char const *c)
{
  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  struct field_data_t* newlyAllocField = &field_data[f];
  columns[ncolumns - 1] = newlyAllocField;

  if (c != nullptr)
    newlyAllocField->caption = c;

  assert (!newlyAllocField->used);

  /* Mark field as used.  */
  newlyAllocField->used = true;
}