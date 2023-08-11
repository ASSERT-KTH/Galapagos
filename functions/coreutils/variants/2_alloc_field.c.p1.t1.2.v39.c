alloc_field(int f, char const *c)
{
  struct field_data_t* new_data_field;     

  columns = (struct field_data_t **)realloc(columns,++ncolumns * sizeof(*columns));
  if(columns)
  {
    for(int i=0; i<f; i++)
    {
      if(!field_data[i].used)
      {
        new_data_field = &field_data[i];
        new_data_field->used = true;
        columns[ncolumns-1] = new_data_field;
        
        if(c != NULL)
        {
          new_data_field->caption = c;
        }
        break;
      }
    }
  }
}