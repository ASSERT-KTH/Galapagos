Variant 1:

void alloc_field1 (int f, char const *c)
{
  assert(!field_data[f].used);  // Assert condition first.
  field_data[f].used = true;  // Mark field as used.

  columns = (typeof(columns))realloc(columns, ++ncolumns * sizeof(struct field_data_t *));
  struct field_data_t* column_data = &field_data[f];
  columns[ncolumns - 1] = column_data;
  if (c)  // Avoid explicit comparison with nullptr.
  {
    column_data->caption = c;
  }
}


Variant 2:

void alloc_field2 (int f, char const *c)
{
  if (! field_data[f].used) 
  {
    field_data[f].used = true;  // Mark the field as used.

    columns = (struct field_data_t**) realloc(columns, sizeof(*columns) * (++ncolumns));
    columns[ncolumns - 1] = &field_data[f];

    if (c) 
    {
      columns[ncolumns - 1]->caption = c; 
    }
  }
}


Variant 3:

void alloc_field3 (int f, char const *c)
{
  assert (!field_data[f].used);  // Let's assert that field hasn't been used yet.

  field_data[f].used = true;  // Mark our field as in use now.

  columns = (struct field_data_t**) realloc(columns, (ncolumns + 1) * sizeof(struct field_data_t *));
  if(columns != nullptr)
  { 
       ncolumns++;
       columns[ncolumns - 1] = &field_data[f];

       if (c)
       {
          columns[ncolumns - 1]->caption = c;
       }
  }
}
