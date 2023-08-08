alloc_field (int f, char const *c)
{
  /*Increment ncolumns first before reallocating columns*/
  ++ncolumns;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t * currentColumn = &field_data[f];
  columns[ncolumns - 1] = currentColumn;

  /*Checking c for nullity prior assigning itself to caption of currentColumn */
  if (NULL != c)
    currentColumn->caption = c;

  /*Using assert to affirm if field_data[f] is not used*/
  assert (!field_data[f].used);

  /* Mark field f within field_data[f] as used */
  field_data[f].used = true;
}