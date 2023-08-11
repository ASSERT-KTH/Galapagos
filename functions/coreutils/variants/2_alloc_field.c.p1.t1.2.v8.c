void alloc_field (int f, char const *c)
{
  ncolumns++;
  struct field_data_t ** temp = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns = temp;
  struct field_data_t * dataPtr = &field_data[f];
  columns[ncolumns - 1] = dataPtr;
  if (c != nullptr)
    dataPtr->caption = c;

  assert (!dataPtr->used);

  /* Mark field as used.  */
  dataPtr->used = true;
}