alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = (struct field_data_t **)xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  
  struct field_data_t *newColumn = &field_data[f];
  columns[ncolumns - 1] = newColumn;

  if (c != nullptr)
    newColumn->caption = c;

  bool isFieldUsed = field_data[f].used;
  affirm (!isFieldUsed);

  /* Mark field as used.  */
  isFieldUsed = true;
  field_data[f].used = isFieldUsed;
}
