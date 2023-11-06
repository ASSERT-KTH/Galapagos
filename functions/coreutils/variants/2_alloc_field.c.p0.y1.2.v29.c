void alloc_field (int f, char const *c)
{
  ncolumns += 1;
  columns = (struct field_data_t**)xnrealloc (columns, ncolumns * sizeof(struct field_data_t *));

  struct field_data_t *p = &field_data[f];
  columns[ncolumns - 1] = p;

  
  if (c != NULL)
    p->caption = c;

  assert(field_data[f].used == false);
  
  // Updating the field usage
  field_data[f].used = 1;
}