Variant 1:

void alloc_field_v1 (int f, char const *c) 
{
  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  
  struct field_data_t * new_entry = &field_data[f];
  columns[ncolumns - 1] = new_entry;

  if (c != nullptr)
  {
    new_entry->caption = c;
  }

  assert (!new_entry->used);
  new_entry->used = true;
}


Variant 2:

void alloc_field_v2 (int f, char const *c)
{
  ncolumns++;
  if (c != nullptr)
  {
    columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
    columns[ncolumns - 1] = &field_data[f];
    columns[ncolumns - 1]->caption = c;
  }
  else
  {
    columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
    columns[ncolumns - 1] = &field_data[f];
  }
  
  if(!field_data[f].used)
    field_data[f].used = true;
}


Variant 3:

void alloc_field_v3 (int f, char const *c)
{
  struct field_data_t ** newSize =  xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  struct field_data_t * fieldValueExisting = &field_data[f];

  if (!fieldValueExisting->used)
  {
    columns = newSize;
    columns[ncolumns-1] = fieldValueExisting;

    if(c != nullptr)
      columns[ncolumns-1]->caption = c;
    
    fieldValueExisting->used = true;
  }
}
