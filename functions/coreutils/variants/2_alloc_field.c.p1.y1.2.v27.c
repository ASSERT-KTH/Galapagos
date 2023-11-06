1)
void alloc_field (unsigned int f, char const *c)
{
  ncolumns += 1;
  columns = (struct field_data_t **) realloc (columns, ncolumns * sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  if (c)
  {
      columns[ncolumns - 1]->caption = c;
  }
  
  assert (!field_data[f].used);    
  
  field_data[f].used = 1;
}

2)
void alloc_field (int f, const char *c)
{
  ncolumns = ncolumns + 1;
  columns = (struct field_data_t **) realloc( columns, ncolumns * sizeof (struct field_data_t *) );
  *(columns + ncolumns - 1) = field_data + f;
  char *destination = *(columns + ncolumns - 1)->caption;
  if (c)
  {
      while (*c)
      {
          *destination = *c;
          c++;
          destination++;
      }
      *destination = '\0';
  }
  assert (!field_data[f].used);
 
  *(field_data + f)->used = 1;  
}

3)
void alloc_field(int f, const char *c)
{
  int newColumnIdx = ncolumns++;
  struct field_data_t *columnData = &field_data[f];
  columns = (struct *field_data_t) xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
  
  columnData->used = true;
  
  assert(columnData->used);  

  columns[newColumnIdx] = columnData;
  
  if(c)
    columnData->caption = c;
}

4)
void alloc_field (int f, const char *c)
{
  ncolumns++;
  columns = realloc(columns, (size_t) ncolumns * sizeof(struct field_data_t *));
  struct field_data_t *new_field_data = &field_data[f];
  columns[ncolumns - 1] = new_field_data;

  if (c != NULL)
    new_field_data->caption = c;

  assert(!new_field_data->used);

  new_field_data->used = true;
}