alloc_field (int f, char const *c)
{
  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));

  struct field_data_t * newColumn = &field_data[f];
  columns[ncolumns - 1] = newColumn;

  if (c){
    newColumn->caption = c;
  }

  assert (newColumn->used == false);

  newColumn->used = true;
}