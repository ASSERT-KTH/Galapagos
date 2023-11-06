Function 1:


void alloc_field(int f, const char *c) 
{
  ncolumns++;
  columns = (field_data_t**)xnrealloc(columns, ncolumns, sizeof(field_data_t*));
  field_data_t *field_ptr = &field_data[f];
  columns[ncolumns - 1] = field_ptr;

  if(c != nullptr)
    columns[ncolumns - 1]->caption = c;

  assert (!field_data[f].used);
  
  field_data[f].used = true;
}


Function 2:


void alloc_field(int f, const char* c)
{ 
  columns = xnrealloc(columns, ++ncolumns, sizeof(struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];

  if(c != nullptr)
    (columns[ncolumns - 1])->caption = c;

  assert (!(columns[ncolumns - 1])->used);
  
  (columns[ncolumns - 1])->used = 1;
}


Function 3:


void alloc_field(int f, const char *c) 
{
  struct field_data_t ** new_columns = xnrealloc(columns, ncolumns += 1, sizeof(struct field_data_t*));
  new_columns[ncolumns - 1] = &field_data[f];
  columns = new_columns;

  if(c != nullptr)
    new_columns[ncolumns - 1]->caption = c;

  assert(!field_data[f].used);
  
  field_data[f].used = true;
}


Function 4:


void alloc_field(int pos, char const *caption) 
{
  ncolumns++;
  columns = (struct field_data_t **)xnrealloc (columns, ncolumns, sizeof(struct field_data_t *));
  columns[ncolumns - 1] = &field_data[pos];
  if(caption != nullptr)
    columns[ncolumns - 1]->caption = caption;

  assert(!field_data[pos].used);
  
  field_data[pos].used = true;
}
