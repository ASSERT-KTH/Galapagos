Variant 1:

alloc_field (int f, char const *c)
{
  struct field_data_t **temp_col = xnrealloc (columns, ncolumns+1, sizeof (struct field_data_t *));

  if (temp_col != nullptr) 
  {
    columns = temp_col;
    ++ncolumns;
    columns[ncolumns - 1] = &field_data[f];
    if (c != nullptr){
        columns[ncolumns - 1]->caption = c;
    }

    if(!field_data[f].used){
        field_data[f].used = true;
    }
  }
}

Variant 2:

alloc_field (int f, char const *c)
{
  struct field_data_t **resized_columns = xnrealloc(columns, ncolumns + 1, sizeof(struct field_data_t *));

  if (!resized_columns){
    return;
  }

  resized_columns[ncolumns++] = &field_data[f];

  if (c)
    resized_columns[ncolumns - 1]->caption = c;

  assert (!field_data[f].used);

  field_data[f].used = true;
  
  columns = resized_columns;
}

Variant 3:

alloc_field (int f, char const *c)
{
  field_data_t **new_columns = (field_data_t **)xnrealloc(columns, ncolumns + 1, sizeof(*new_columns));
  if (new_columns == nullptr){
      return;
  }
  
  ncolumns++;
  new_columns[ncolumns-1] = &field_data[f];
  if(c) new_columns[ncolumns-1]->caption = c;
  
  assert (!field_data[f].used);
  
  field_data[f].used = 1;
  columns = new_columns;
}
