alloc_field (int f, char const *c)
{
  ncolumns++;
  void *temp_columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  if (temp_columns == nullptr)
    return;
  
  columns = static_cast<struct field_data_t **>(temp_columns);
  struct field_data_t* p = &field_data[f];

  if (!p->used) 
  {
    columns[ncolumns - 1] = p;
    if (c != nullptr)
      p->caption = c;
    p->used = true;
  }
}