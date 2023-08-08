void alloc_field (int f, char const *c)
{
  if( f < 0 || !c )
    return;

  ncolumns++;
  columns = (struct field_data_t **) realloc (columns, ncolumns * sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  
  if (c != nullptr){
    int caption_size = strlen(c) + 1;
    columns[ncolumns - 1]->caption = (char*) malloc(caption_size);
    strncpy(columns[ncolumns - 1]->caption, c, caption_size);
  }

  if(field_data[f].used){
    printf("%s - field is already used\n", c);
    return;
  }

  /* Mark field as used.  */
  field_data[f].used = true;
}