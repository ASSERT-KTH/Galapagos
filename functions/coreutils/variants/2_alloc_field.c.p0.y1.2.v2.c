void alloc_field (int f, char const *c)
{
  field_data[f].used == false ? field_data[f].used = true : NULL;

  struct field_data_t **temp;
  temp = (struct field_data_t **) realloc (columns, (++ncolumns) * sizeof(struct field_data_t *)) ;

  if (temp != nullptr)
  {
    columns = temp;
    columns[ncolumns - 1] = &field_data[f];
	
    if (c != nullptr) columns[ncolumns - 1]->caption = c;
  }
  else
  {
    // optionally handle realloc failure
    exit(-1);
  }
}