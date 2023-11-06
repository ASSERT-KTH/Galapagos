void alloc_field (int f, const char *c)
{
  ncolumns++;
  columns = (struct field_data_t**) realloc (columns, ncolumns * sizeof (struct field_data_t *));
  
  if(columns != NULL)
  {
    columns[ncolumns - 1] = &field_data[f];
    if (c)
      columns[ncolumns - 1]->caption = c;

    if(!field_data[f].used)
    {
      field_data[f].used = true;
    }
    else
    {
      printf("Field already used");
    }
  }
  else
  {
    printf("Memory not allocated");
  }
}