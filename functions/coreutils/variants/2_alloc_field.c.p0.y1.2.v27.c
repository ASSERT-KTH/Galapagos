void alloc_field(int f, const char* c) {
  struct field_data_t* tmpColumns = (struct field_data_t**)realloc(columns, (ncolumns + 1) * sizeof(struct field_data_t*));

  if (tmpColumns != nullptr)
  {
    columns = tmpColumns;
    struct field_data_t* newField = new struct field_data_t;
    newField->id = f;

    if(c != nullptr) {
      newField->caption = c;
    }
    newField->used = true;

    columns[ncolumns++] = newField;

    if(!newField->v_o_other_var) {
      if(!field_data[f].v_o_other_var)
      {
        newField->v_o_other_var = true; // when field is used, so value becomes true.
      }
    }
  }
  else
  {
    free(columns);
    printf("Error reallocating memory!");
    exit(1);
  }

  if(field_data[f].used) {
    printf("Field_data in use!");

    /* Add cleanup code if needed */
  }
}