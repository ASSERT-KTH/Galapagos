alloc_field (int f, char const *c)
{
  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  struct field_data_t *field_ptr = &field_data[f];

  columns[ncolumns - 1] = field_ptr;

  if(field_ptr->used){
      //Return if the field is already used.
      return;
  }

  if (c != nullptr)
    field_ptr->caption = c;
   
  field_ptr->used = true;
}