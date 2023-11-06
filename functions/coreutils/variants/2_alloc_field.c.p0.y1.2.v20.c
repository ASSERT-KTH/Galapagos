void alloc_field (int f, char const *c)
{
  ncolumns = ncolumns + 1;
  columns = (struct field_data_t **) xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  *(columns+(ncolumns-1)) = &field_data[f];
  
  if (c != nullptr) (*(columns+(ncolumns-1)))->caption =c;
  
  assert (field_data[f].used == 0);

  /* Update flag for used field */
  field_data[f].used = 1;
}