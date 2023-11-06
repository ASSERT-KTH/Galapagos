1. Changing the order of operations inside the if statement and allocating memory in a separate step:

void alloc_field (int f, char const *c) {
  struct field_data_t **temp_columns;
  
  assert (!field_data[f].used);
  field_data[f].used = true;

  ncolumns++;
  temp_columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns = temp_columns;
  
  columns[ncolumns - 1] = &field_data[f];
  
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;
}

2. Using ternary operator:

void alloc_field (int f, char const *c) {
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  
  columns[ncolumns - 1]->caption = (c != nullptr) ? c : columns[ncolumns - 1]->caption;

  assert (!field_data[f].used);
  field_data[f].used = true;
}

3. Using a single line for allocation and indexing:

void alloc_field (int f, char const *c) {
  assert (!field_data[f].used);
  field_data[f].used = true;

  *(columns = xnrealloc (columns, ++ncolumns, sizeof(*columns))) [ncolumns - 1] = &field_data[f];
  
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;
}

4. Using goto instead of if in case of NULL string:

void alloc_field(int f, char const *c) {
  if (c == nullptr) goto skip_caption_assignment;

  ncolumns++;
  columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  columns[ncolumns - 1]->caption = c;

  skip_caption_assignment:
  assert(!field_data[f].used);
  field_data[f].used = true;
}
