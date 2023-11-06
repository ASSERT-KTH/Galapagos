Variant 1:

void alloc_field(int f, const char *c) {
  columns = (struct field_data_t**)realloc(columns, (ncolumns + 1) * sizeof(struct field_data_t *));
  ncolumns++;

  columns[ncolumns - 1] = f >= 0 && f < ncolumns ? &field_data[f] : NULL;
  if (c != NULL) columns[ncolumns - 1]->caption = c;

  assert(!field_data[f].used);
  field_data[f].used = 1;
}


Variant 2:

void alloc_field(int f, const char *c) {
  struct field_data_t **tempCol = (struct field_data_t**)realloc(columns, (ncolumns + 1) * sizeof(struct field_data_t *));
  
  if(tempCol != NULL) {
    columns = tempCol;
    ncolumns++;
    
    if(f >= 0 && f < ncolumns) {   
      tempCol[ncolumns - 1] = &field_data[f];
      if(c != NULL) tempCol[ncolumns - 1]->caption = c;
      
      assert(!field_data[f].used);
      field_data[f].used = 1;
    }
  }  
}


Variant 3:

void alloc_field(int f, const char *c) {
  struct field_data_t **new_columns = realloc(columns, (ncolumns + 1) * sizeof *new_columns);
  
  if (new_columns) {
    columns = new_columns;
    
    struct field_data_t *new_field = calloc(1, sizeof *new_field);
    
    if(new_field) {
      new_columns[ncolumns++] = new_field;

      if (c != NULL) new_field->caption = strdup(c);
    } 
  }
  
  assert(!field_data[f].used);
  field_data[f].used = 1;
}
