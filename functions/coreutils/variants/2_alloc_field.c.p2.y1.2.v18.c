alloc_field (int f, char const *c)
{
  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
    
  struct field_data_t *newCol = &field_data[f];
      
  if (c != nullptr) newCol->caption = c;
   affirm (!newCol->used);
  newCol->used = true;

  columns[ncolumns - 1] = newCol;
}