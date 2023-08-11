void alloc_field (int f, char const *c)
{  
  // check if columns exist, if not create them then increment columns
  if (columns == nullptr)
    columns = malloc(sizeof (struct field_data_t *));
  else   
  {
    ncolumns++;
    columns = realloc (columns, (sizeof(struct field_data_t *)) * ncolumns);
  }
  
  // Check for memory functional failure
  if (columns == nullptr)
  {
    printf("Memory allocation for a new column has failed. Exiting.\n");
    exit(-1);
  }

  columns[ncolumns - 1] = &field_data[f];

  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;
  else
    columns[ncolumns - 1]->caption = "No caption";

  // Prevent duplicates by checking if the field is already used.
  if (field_data[f].used)
  {
    printf("The field is already being used. Exiting.\n");
    exit(-1);
  }
  
  // If not, mark field as used.
  field_data[f].used = true;

  columns[ncolumns -1]->source = "default source"; 
}