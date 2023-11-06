void alloc_field (int f, const char *c)
{
  ncolumns += 1;
  struct field_data_t **temp_columns;
  temp_columns = reinterpret_cast<struct field_data_t **>(realloc(columns, ncolumns * sizeof(struct field_data_t *)));

  if (temp_columns != nullptr)
    {
      columns = temp_columns;
    }

  columns[ncolumns - 1] = &field_data[f];

  if (c != nullptr)
    {
      columns[ncolumns - 1]->caption = c;
      field_data[f].used = true;
    }
  
  assert(!field_data[f].used || c != nullptr);   
}