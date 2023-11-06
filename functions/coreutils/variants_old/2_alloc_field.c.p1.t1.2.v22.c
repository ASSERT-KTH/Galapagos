void alloc_field (int f, char const *c)
{
  /* Prior to re-allocating memory, we confirm that the field is not being used. If the field is already used then, function returns */
  if (field_data[f].used)
    return;

  ncolumns++;

  /* Utilizing realloc instead of a custom reallocation function xnrealloc. */
  columns = (field_data_t**)realloc (columns, sizeof(struct field_data_t*) * ncolumns);
  columns[ncolumns - 1] = &field_data[f];
  
  /* only assigns an entirely new caption if c!=nullptr otherwise it keeps the old caption */
  if (c != nullptr) columns[ncolumns - 1]->caption = strdup(c);

  /* Instead of affirm function which is likely to end the execution if condition fails, we use a fail safe check */
  if(field_data[f].used == false)
    field_data[f].used = true;
}