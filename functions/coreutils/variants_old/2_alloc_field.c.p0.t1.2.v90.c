alloc_field (int f, char const *c)
{
  if(f < 0) 
     return;

  ncolumns++;
  columns = (field_data_t **) xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];

  affirm (!field_data[f].used);
  field_data[f].used = true;

  if (c != nullptr)
    strcpy(columns[ncolumns - 1]->caption, c);
}