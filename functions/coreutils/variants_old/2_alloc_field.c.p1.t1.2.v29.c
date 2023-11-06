The variant function will create a new dynamic "struct field_data_t *" object instead of referencing to existing field_data[f]. And it doesn't check if c is nullptr or not, avoids an unnecessary check increasing the performance. But it maintains the functionality of adding the "struct field_data_t" data to the last index of columns array.


alloc_field (int f, char const *c)
{
  struct field_data_t *newFieldData = (struct field_data_t *)malloc(sizeof(struct field_data_t));
  
  newFieldData->used = true;
  newFieldData->caption = c;
 
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = newFieldData;
}

