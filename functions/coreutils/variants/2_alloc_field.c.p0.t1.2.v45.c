alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  if (!field_data[f].used)
  {
      field_data[f].used = true;
      columns[ncolumns - 1] = &field_data[f];
  }
  else
      return;  // return if field is already used

  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;
}