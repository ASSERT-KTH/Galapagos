void alloc_field (int f, char const *c)
{
  ++ncolumns;
  columns = (struct field_data_t **)realloc(columns, ncolumns * sizeof(struct field_data_t *));
  
  if (columns)
  {
    field_data[f].used = true;
    columns[ncolumns - 1] = field_data + f;
    
    if(c) 
    {
      columns[ncolumns - 1]->caption = c;
    }
    else
    {
      columns[ncolumns - 1]->caption = NULL;
    }
  }
  else
  {
    exit(EXIT_FAILURE);     
  }
}