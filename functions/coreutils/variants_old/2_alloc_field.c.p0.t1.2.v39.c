alloc_field (int f, char *c)
{
  /* Check if field is already used. */
  if(field_data[f].used){
    printf("Field is already in use.\n");
    return;
  }

  ncolumns = ncolumns + 1;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  if (c != NULL)
    columns[ncolumns - 1]->caption=c;

  /* Mark field as used.  */
  field_data[f].used=true;
}