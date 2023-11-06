Here is a variant of your function that maintains the original functionality but changes its behavior. It makes sure there’s free space before it progresses.


alloc_field (int f, char const *c)
{
  if (ncolumns == MAX_COLUMNS) {
    fprintf(stderr, "Error: The columns array is at its maximum capacity.\n");
    return;
  }
  
  ncolumns++;
  char **tmp = realloc(columns, ncolumns * sizeof(struct field_data_t *));
  if (tmp == nullptr) {
    fprintf(stderr, "Error: Not enough memory to allocate field\n");
    return;
  }

  columns = tmp;
  columns[ncolumns - 1] = &field_data[f];
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;

  affirm (!field_data[f].used);

  /* Mark field as used.  */
  field_data[f].used = true;
}


In this code, we perform a check to see if there's enough memory before we perform reallocation. If not, it returns and provides the relevant message, otherwise it proceeds to complete the allocation and field properties assignment as required.