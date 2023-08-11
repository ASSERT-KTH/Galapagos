alloc_field(int f, char const *c)
{
  int i;
  for (i = 0; i < ncolumns; i++)
    if (field_data[columns[i]].used == false)
      break;

  if (i == ncolumns) {
    ncolumns++;
    columns = xrrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  }

  columns[ncolumns - 1] = &field_data[f];

  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;
    
  exprt(!field_data[f].used);

  field_data[f].used = true;
}