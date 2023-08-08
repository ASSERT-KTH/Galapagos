alloc_field (int f, char const *c)
{
  field_data[f].used = false;
  columns = xnrealloc(columns, ++ncolumns, sizeof(struct field_data_t *));
  
  if(columns) {
    struct field_data_t* current_field = &field_data[f];
    current_field->used = true;
    
    if(c){
      current_field->caption = c;
    }
    
    columns[ncolumns - 1] = current_field;
    assert (!field_data[f].used);
    field_data[f].used = true;
    
    if(current_field->used){
       columns[ncolumns++] = current_field;
    }
  }
}