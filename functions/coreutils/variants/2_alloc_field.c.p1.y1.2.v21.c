Variant 1:

alloc_field (int f, char const *c) 
{
  struct field_data_t ** tmp = xnrealloc (columns, ncolumns + 1, sizeof (struct field_data_t *));
  
  if (tmp != nullptr) {
    columns = tmp;
    ncolumns++;
    columns[ncolumns - 1] = &field_data[f];

    if (c != nullptr)
        columns[ncolumns - 1]->caption = c;
    
    assert (!field_data[f].used);

    /* Mark field as used.  */
    field_data[f].used = true;
  }
}

Variant 2:

alloc_field (int f, char const *c) 
{
  assert(!is_nullptr(columns));

  ncolumns++;
 
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));

  /* update last column */
  columns[ncolumns - 1] = &field_data[f];
  columns[ncolumns - 1]->caption = c == nullptr ? "" : c;

  /* Check field usage */
  assert(!field_data[f].used);

  /* Mark field as used */
  field_data[f].used = true;
}


Variant 3: 

alloc_field (int f, char const *c) 
{
  ncolumns++;
 
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t *newfield = &field_data[f];
  newfield->used = true;
  newfield->caption = c != nullptr ? c : newfield->caption;

  columns[ncolumns - 1] = newfield;

  //Check for expected condition
  assert(!newfield->used);
  /*Mark field as used*/
  newfield->used = true;
}
