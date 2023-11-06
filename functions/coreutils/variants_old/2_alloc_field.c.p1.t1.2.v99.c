void alloc_field(int f, char const *c)
{
  assert(f >= 0); // Checking if field index f is non-negative.
  assert(f < MAX_FIELDS); // Checking if field index f is within expected range.
  
  // Processing column data.
  field_data_t *temp_field_data = (field_data_t*)realloc(columns, (ncolumns + 1) * sizeof(field_data_t*));

  if(temp_field_data == NULL)
    {
      printf("Memory allocation failed!\n"); // This print statement is needed to inform the user of a potential memory error.
      return; // Return statement added to return in case of error.
    }

  columns = temp_field_data;
  ncolumns++;

  struct field_data_t *selectedField_ptr = &field_data[f];

  /* First check if this field is being used before */
  if(selectedField_ptr->used){
      printf("Field is already used!\n"); // This print statement is needed to inform the user that tag is already used.
      return;
  }
  
  
  columns[ncolumns - 1] = selectedField_ptr;
  if (c)
    columns[ncolumns - 1]->caption = malloc(strlen(c)+1);

  if(columns[ncolumns - 1]->caption){
    strcpy(columns[ncolumns - 1]->caption, c);
  }

  selectedField_ptr->used = true;

}