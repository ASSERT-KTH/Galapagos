1. Option to pre-increment 'ncolumns'

alloc_field (int f, char const *c)
{
  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;

  affirm (!field_data[f].used);

  /* Mark field as used.  */
  field_data[f].used = true;
}


2. Using 'else' instead of 'affirm' to make sure 'field_data[f].used' is not true.

alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;

  if (!field_data[f].used)
  {
    /* Mark field as used.  */
    field_data[f].used = true;
  }
}


3. Tweaking 'if' conditions.

alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];

  if (c)
    columns[ncolumns - 1]->caption = c;

  affirm (!field_data[f].used);

  /* Mark field as used.  */
  field_data[f].used = true;
}

4. Direct Access to the last element of 'columns' array.

alloc_field (int f, char const *c)
{
  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  struct field_data_t **lastColumn = &columns[ncolumns - 1];  
  *lastColumn = &field_data[f];

  if (c)
    (*lastColumn)->caption = c;

  affirm (!field_data[f].used);

  /* Mark field as used.  */
  field_data[f].used = true;
}
