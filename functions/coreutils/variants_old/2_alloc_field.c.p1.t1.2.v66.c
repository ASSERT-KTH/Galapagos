void alloc_field (int f, char const *c)
{
  assert(f < MAX_FIELD && f >= 0); // Adding field bounds checking
    
  field_data[f].used = true; // Moving up and using field immediately
    
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t *selectedField = &field_data[f];
    
  assert(selectedField); // Null-checking for selectedField
     
  columns[ncolumns - 1] = selectedField;  
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;
}