
void alloc_field2(int f, const char *c)
{
  ncolumns++;
  columns = xnrealloc(columns, ncolumns * sizeof(struct field_data_t *));
  
  field_data[f].used = true;
  columns[--ncolumns] = field_data + f;

  if (c)
    columns[ncolumns]->caption = c;

  /* Reset field to unused for later use */
  field_data[f].used = false;
}

void alloc_field3(int f, const char *c)
{
  columns = xnrealloc(columns, ++ncolumns * sizeof(struct field_data_t *));

  field_data[f].used = true;
  struct field_data_t *data = &field_data[f];

  if (c)
    data->caption = c;
    
  columns[ncolumns - 1] = data;
  
  /* Reset field to unused for dater use */
  field_data[f].used = false;
}


void alloc_field4(int f, const char *c)
{
  field_data_t* new_data = &field_data[f];
    
  if (c != nullptr){
    new_data->caption = c;
  }

  columns = (field_data_t **)xnrealloc (columns, (ncolumns + 1) * sizeof(struct field_data_t *));
  columns[ncolumns] = new_data;
  ++ncolumns;

  /* Remember to specify that the field is used */
  new_data->used = true;
}
