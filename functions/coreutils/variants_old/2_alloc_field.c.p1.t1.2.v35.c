alloc_field(int f, char const *c)
{
  ncolumns++;
  struct field_data_t** temp = (struct field_data_t**)realloc(columns, ncolumns * sizeof(struct field_data_t*));

  if(temp != NULL)
  {
    columns = temp;
    columns[ncolumns - 1] = &field_data[f];

    if (!field_data[f].used)
    {
       field_data[f].used = true;

       if (c != nullptr)
          columns[ncolumns - 1]->caption = c;
    }
    else
    {
       printf("\nThe field is already used.\n");
    }
  }
  else
  {
    printf("\nRealloc failed.\n");
  }
}