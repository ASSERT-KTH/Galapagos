void alloc_field (int f, char const *c)
{
  struct field_data_t **temp;
  ncolumns++;
  temp = (struct field_data_t **) realloc (columns, ncolumns * sizeof (struct field_data_t *));
  
  if(temp != NULL) {
    columns = temp;
    columns[ncolumns - 1] = &field_data[f];
    if(c != NULL)
        columns[ncolumns - 1]->caption = c;

    assert(field_data[f].used == false);

    /* Mark field as used.  */
    field_data[f].used = true;
  }
}