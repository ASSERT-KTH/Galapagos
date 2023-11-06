alloc_field (int f, char const *c)
{
  assert(f >= 0 && "Field index must not be negative!");

  columns = (struct field_data_t **)realloc(columns, (++ncolumns) * sizeof (struct field_data_t *));
  
  if(!columns) {
    fprintf(stderr, "Memory reallocation failed!\n");
    exit(EXIT_FAILURE);
  }

  columns[ncolumns - 1] = &field_data[f];

  assert (!field_data[f].used && "Field should not be used before!");
  
  if (c != nullptr)
    columns[ncolumns - 1]->caption = strdup(c);

  /* Mark field as used. */
  field_data[f].used = true;
}