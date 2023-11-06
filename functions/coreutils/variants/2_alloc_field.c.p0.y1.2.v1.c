void alloc_field (int f, char const *c)
{
  ncolumns += 1;
  
  columns = (struct field_data_t **)xnrealloc 
    (columns, ncolumns, sizeof (struct field_data_t *));
  
  (*(columns + ncolumns - 1)) = field_data + f;
  
  assert(!(*(field_data + f)).used);

  if (c)
    (*(columns + ncolumns -1)) -> caption = c;

  (*(field_data + f)).used = 1;
}