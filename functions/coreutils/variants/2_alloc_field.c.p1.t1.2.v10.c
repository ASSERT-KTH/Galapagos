void alloc_field (int f, char const *c)
{
  // allocate more space for 'columns'
  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));

  // reference the field
  struct field_data_t *field = &field_data[f];

  // make sure this field is unused. If not, reset!
  if(field->used) {
    field->used = false;
    field->caption = nullptr;
  }

  // assign the field to the last slot
  columns[ncolumns - 1] = field;

  // if caption comes in, replace default 
  if (c != nullptr)
    field->caption = c;

  // Mark field as used
  field->used = true;
}