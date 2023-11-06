Variant 1:

void alloc_field (int f, char const *c)
{
  columns = (struct field_data_t **) realloc(columns, (ncolumns + 1) * sizeof(struct field_data_t *));
  
  if (columns != NULL) 
  {
    ncolumns++;
    columns[ncolumns - 1] = &field_data[f];
  }

  if (c != NULL)
  {
    columns[ncolumns - 1]->caption = c;
  }

  assert(!field_data[f].used);

  field_data[f].used = true;
}


Variant 2:

void alloc_field (int f, char const *c)
{
  columns = xnrealloc (columns, (ncolumns + 1), sizeof (struct field_data_t *));
  ncolumns++;
  struct field_data_t *new_column = &field_data[f];
  columns[ncolumns - 1] = new_column;

  if (c != NULL)
  {
    new_column->caption = c;
  }

  assert(!new_column->used);

  /* Mark field as used.  */
  new_column->used = true;
}


Variant 3:

void alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t *field = &field_data[f];
  columns[ncolumns - 1] = field;

  if (c)
  {
    field->caption = c;
  }

  if (field->used)
  {
    fprintf(stderr, "Error: Field already used.\n");
    exit(EXIT_FAILURE);
  }

  /* Mark field as used.  */
  field->used = true;
}

