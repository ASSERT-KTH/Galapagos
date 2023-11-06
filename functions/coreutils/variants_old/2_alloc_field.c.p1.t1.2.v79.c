alloc_field (int f, char const *c)
{
  struct field_data_t ** temp_columns = (struct field_data_t **) realloc(columns, (ncolumns + 1) * sizeof (struct field_data_t *));
  if(temp_columns != nullptr)
  {
    columns = temp_columns;
    ncolumns++;
   
    columns[ncolumns - 1] = &field_data[f];
    if (c != nullptr)
        columns[ncolumns - 1]->caption = c;

    assert(field_data[f].used == false);
    field_data[f].used = true;
  }
}