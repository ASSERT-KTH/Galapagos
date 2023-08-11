alloc_field (int f, const char *c)
{
  ncolumns++;
  struct field_data_t* localColumn = &field_data[f];
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = localColumn;
  
  assert (!localColumn->used);
  localColumn->used = true;
  
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;
}