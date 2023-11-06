alloc_field (int f, char const *c)
{
  if (!field_data[f].used)
  {
    ncolumns++;
    struct field_data_t ** temp = (struct field_data_t **)realloc(columns, ncolumns* sizeof (struct field_data_t *));
    if (temp == NULL)
    {
        fprintf(stderr, "Error reallocating memory\n");
        return;
    }
    else 
    {
        columns = temp;
    }

    columns[ncolumns - 1] = &field_data[f];
    field_data[f].used = true;

    if (c)
    { 
      columns[ncolumns - 1]->caption = c;
    }
  }
  else
  {
    fprintf(stderr, "This field is already in use.\n");
  }
}