Version 1:

void alloc_field(int f, const char* c) {
  ncolumns++;
  columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
  struct field_data_t *field = &field_data[f];
  columns[ncolumns - 1] = field; 

  if (c) {
    field->caption = c;
  }
  
  assert(!field->used);

  field->used = true;
}
			  
Version 2:

void alloc_field(int f, const char* c) {
  columns = xnrealloc (columns, ++ncolumns, sizeof(struct field_data_t *));
  struct field_data_t *newField = &field_data[f];
  columns[ncolumns - 1] = newField;
  
  if (c)
	newField->caption = c;
	
  assert(!newField->used);

  newField->used = true; 
}
	          		 
Version 3:

void alloc_field(int f, const char* c) {
  struct field_data_t *fdata = &field_data[f];
  assert(!fdata->used);

  ncolumns++;
  columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
  columns[ncolumns - 1] = fdata;

  if (c)
    fdata->caption = c;

  fdata->used = true;
}
	       			   

Version 4:

void alloc_field(int f, const char* c) {
  columns = xnrealloc (columns, ++ncolumns, sizeof(struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];

  if (c != nullptr){
	columns[ncolumns - 1]->caption = c;
  }

  assert(!field_data[f].used);
 
  field_data[f].used = true;
}
