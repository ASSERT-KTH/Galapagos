alloc_field (int f, char const *c)
{
  ncolumns = ncolumns + 1; // increment number of columns
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  int lastIndex = ncolumns - 1; // information about last index
  columns[lastIndex] = &field_data[f];
  // if caption is not null
  if (c != nullptr)
    columns[lastIndex]->caption = c;

  // affirm field not in use
  affirm (!(field_data[f].used));
  
  /* Mark field as used.  */
  field_data[f].used = 1;
}