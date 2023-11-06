alloc_field (int f, char const *c)
{
  if (!field_data[f].used){
    ++ncolumns;
    columns = (struct field_data_t**)realloc(columns, ncolumns * sizeof(struct field_data_t*));
    columns[ncolumns - 1] = &field_data[f];
    if(c) {
      columns[ncolumns - 1]->caption = (char*)c;
    }

    field_data[f].used = 1;
  }
}