void alloc_field(int f, char const *c)
{
  ncolumns++;
  
  columns = (struct field_data_t **) realloc (columns, ncolumns * sizeof (struct field_data_t *));
  
  struct field_data_t* temp_field_data = &field_data[f];
  columns[ncolumns - 1] = temp_field_data;
  
  if (c != NULL)
  {
    columns[ncolumns - 1]->caption = c;
  }

  if (field_data[f].used == false) 
  {
      field_data[f].used = true;
  }
}