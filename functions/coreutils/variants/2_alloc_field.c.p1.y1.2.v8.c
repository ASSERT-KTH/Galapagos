1. Adding check for "columns" memory allocation:


alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  if(columns){
    columns[ncolumns - 1] = &field_data[f];
    if (c != nullptr)
      columns[ncolumns - 1]->caption = c;
    affirm (!field_data[f].used);
    field_data[f].used = true; // Mark field as used
  }
}


2. Replacement of `xnrealloc()` with `realloc()`:


alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = (struct field_data_t **)realloc(columns, ncolumns*sizeof(struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;

  affirm (!field_data[f].used);

  field_data[f].used = true; // Mark field as used
}


3. Exiting function if function pointer passed in `c==nullptr`:


alloc_field (int f, char const *c)
{
  if (c == nullptr) return;
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  columns[ncolumns - 1]->caption = c;

  affirm (!field_data[f].used);

  field_data[f].used = true; // Mark field as used
}


4. Nullify `caption` if `c == nullptr`:


alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;
  else
    columns[ncolumns - 1]->caption = nullptr;

  affirm (!field_data[f].used);

  field_data[f].used = true; // Mark field as used
}
