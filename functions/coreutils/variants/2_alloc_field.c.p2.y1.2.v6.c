alloc_field(int f, char const *c) 
{
  columns = (struct field_data_t **) xrealloc (columns, (ncolumns+1) * sizeof (struct field_data_t *));
  ncolumns++;
  struct field_data_t *newField = &field_data[f];
  columns[ncolumns - 1] = newField;

  if(c != NULL) 
  {
    newField->caption = c;
  }

  assert(newField->used == false);
  
  newField->used = true;
}