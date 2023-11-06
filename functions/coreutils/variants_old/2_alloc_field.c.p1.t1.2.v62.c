void alloc_field (int f, char const *c)
{
  /* Check if the field is already used or not.
  Continue the execution only if the field is 
  not used irrespective of passed caption.*/
  if (field_data[f].used)
    return;

  /* Increment column count */
  ncolumns++;

  /* Allocate or reallocate memory based on column count */
  columns = (struct field_data_t**) realloc(columns, ncolumns * sizeof(struct field_data_t *));
  if (columns == NULL)
    return;

  /* Assign field to the newly made space */
  columns[ncolumns - 1] = &field_data[f];

  /* If caption is provided, assign it to the field */
  if (c != NULL)
    columns[ncolumns - 1]->caption = c;

  /* Mark field as used */
  field_data[f].used = true;
}