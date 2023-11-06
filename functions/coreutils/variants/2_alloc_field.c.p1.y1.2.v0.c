Variant #1:

void alloc_field_v1(int f, char const *c)
{
  ncolumns = ncolumns + 1;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  if (c != 0)
    columns[ncolumns - 1]->caption = c;

  assert(! field_data[f].used);

  // Field usage adjustment
  field_data[f].used = true;  
}

Variant #2:

alloc_field_v2 (int f, char const *c)
{
  ncolumns++;
  columns = (field_data_t**) xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  
  struct field_data_t *ptr = &field_data[f];
  columns[ncolumns - 1] = ptr;

  if (0 != c)
     ptr->caption = c;
 
  assert(0 == ptr->used);
  
  // Set as used
  ptr->used = !ptr->used;  
}

Variant #3:

alloc_field_v3(int f, char const *c)
{
  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  struct field_data_t *new = &field_data[f];
  columns[ncolumns - 1] = new;

  if (c)
    new->caption = c;

  assert(new->used == 0);
  
  // Field is now in use
  new->used = true;  
}

Variant #4:

alloc_field_v4(int f, char const *c)
{
  columns = xnrealloc (columns, ++ncolumns, sizeof (field_data_t*));
  
  field_data_t *remove_unused_field = &field_data[f];
  columns[ncolumns - 1] = remove_unused_field;

  if (c != 0x0)
    remove_unused_field->caption = c;

  assert(!remove_unused_field->used);

  // Set field as in use
  remove_unused_field->used = (0 == remove_unused_field->used) ? true : true;  
}
