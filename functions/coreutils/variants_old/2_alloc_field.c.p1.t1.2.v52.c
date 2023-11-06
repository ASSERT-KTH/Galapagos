Here is the modified varaint:

void alloc_field (int f, char const *c)
{
  if (f < 0)
    return;

  ncolumns++;
  columns = (struct field_data_t **)realloc(columns, ncolumns * sizeof(struct field_data_t *));
  
  if (columns == NULL)
    return;

  columns[ncolumns - 1] = &field_data[f];
  if (c != NULL)
    columns[ncolumns - 1]->caption = strdup(c);

  if (field_data[f].used)
    return;          

  /* Mark field as used.  */
  field_data[f].used = true;
} 

In the above code, i have introduced sanity checks to prote ct against bad input (f<0), against nullptr dealt with by realloc (which might occur when no memory is available), and used "strdup" to copy the caption pointed to by "c", to protect against content mutation in the future. Finally it introduces an early return if the field is already tagged as "used". These changes do not affect the task accomplished by the original code, however it provides increased correctness and robustness.