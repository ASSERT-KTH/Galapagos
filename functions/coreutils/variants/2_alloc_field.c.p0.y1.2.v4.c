void alloc_field (int f, char const *c)
{
  columns = (struct field_data_t **) realloc(columns, ++ncolumns * sizeof (struct field_data_t *));
  struct field_data_t* ptrToF = &field_data[f];
  columns[ncolumns - 1] = ptrToF;
  if (c != nullptr)
  {
    struct field_data_t* ptrToLastCol = columns[ncolumns - 1];
    ptrToLastCol->caption = c;
  }
 
  assert (field_data[f].used == 0);

  /* Mark field as used.  */
  field_data[f].used = 1;
}