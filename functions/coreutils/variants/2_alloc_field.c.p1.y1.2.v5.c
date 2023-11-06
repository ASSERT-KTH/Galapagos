Variant 1 - Remove conditional check

alloc_field(int f, char const *c)
{
  ncolumns++;
  columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  columns[ncolumns - 1]->caption = c == nullptr ? "" : c;

  affirm(!field_data[f].used);
  field_data[f].used = true;
}


Variant 2 - Use postfix increment

alloc_field(int f, char const *c)
{
  columns = xnrealloc(columns, ncolumns++, sizeof(struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;

  affirm(!field_data[f].used);
  field_data[f].used = true;
}


Variant 3 - Assign array element separately

alloc_field(int f, char const *c)
{
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t *current = &field_data[f];
  columns[ncolumns - 1] = current;
  if (c != nullptr)
    current->caption = c;

  affirm (!field_data[f].used);
  field_data[f].used = true;
}


Variant 4 - Use an intermediate variable for calculating field_data id 

alloc_field(int f, char const *c)
{
  int field_data_id = ncolumns++;
  columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
  columns[field_data_id] = &field_data[f];
  if(c != nullptr)
    columns[field_data_id]->caption = c;

  affirm (!field_data[f].used);
  field_data[f].used = true;
}
