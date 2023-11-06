
void alloc_field (int f, char const *c)
 {
  /* New code for handling negative indices. */
  if (f < 0)
    f = ncolumns + f;

  ncolumns++;
  columns = (struct field_data_t **) realloc(columns, ncolumns * sizeof(struct field_data_t *));
 
  if(columns == nullptr) 
  {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
  }
  
  columns[ncolumns - 1] = &field_data[f];

  if(columns[ncolumns - 1]== nullptr) 
  {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
  }

  /* Check if input string for caption is null ptr, assign an empty string instead. */
  if(c != nullptr) 
     columns[ncolumns - 1]->caption = c; 
  else 
     columns[ncolumns - 1]->caption = "";

  if (field_data[f].used)
     perror("Field data already used");

  /* Inserted fflush(stdout) to clear any existing buffer.*/
  fflush(stdout);

  /* Mark field as used.  */
  field_data[f].used = true;
}
