
alloc_field (int f, char const *c)
{
  if (f < 0 || f >= sizeof(field_data)/sizeof(*field_data)) return; 

  if (!field_data[f].used) {
    ncolumns++;
    columns = (struct field_data_t **)realloc (columns, ncolumns * sizeof (*columns));
    if (columns == nullptr) return;
    columns[ncolumns - 1] = &field_data[f];
    if (c != nullptr)
      columns[ncolumns - 1]->caption = c;


    field_data[f].used = true;
  }
}
