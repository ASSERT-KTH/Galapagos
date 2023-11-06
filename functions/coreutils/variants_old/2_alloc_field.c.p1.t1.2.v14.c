alloc_field (int f, char const *c)
{
  assert(f >= 0 && f < sizeof(field_data)/sizeof(field_data[0]));

  ncolumns++;
  struct field_data_t **temp = (struct field_data_t **) realloc(columns, ncolumns * sizeof(struct field_data_t *));
  if(!temp){
    fprintf(stderr, "Failed to allocate memory\n");
    exit(1);
  }
  columns = temp;

  columns[ncolumns - 1] = &field_data[f];
  
  if (c != nullptr){
    size_t len = strlen(c) + 1;
    char* c_copy = (char* )malloc(sizeof(char) * len);
    if (!c_copy){
      fprintf(stderr, "Failed to allocate memory for string %s\n", c);
      exit(1);
    }
    strcpy(c_copy, c);
    columns[ncolumns - 1]->caption = c_copy;
  }

  /* if the field is already being used, release the lastly occupied 
     space we just incremented, else mark field as used. For 
     both conditions, add proper diagnose */
  if (field_data[f].used){  
    ncolumns--;
    fprintf(stderr, "Field %d is already used.", f);
    exit(EXIT_FAILURE);
  }
  else {
    field_data[f].used = true;
  }
}