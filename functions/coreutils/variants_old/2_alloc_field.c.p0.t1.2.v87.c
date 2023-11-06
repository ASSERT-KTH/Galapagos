void alloc_field (int f, char const *c)
{
  ncolumns += 1;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  
  affirm (!field_data[f].used);
  
  field_data[f].used = true; // Move "used" assignment here

  columns[ncolumns - 1] = &field_data[f];
    
  if (c != nullptr)
  {
    columns[ncolumns - 1]->caption = c;
  }

}