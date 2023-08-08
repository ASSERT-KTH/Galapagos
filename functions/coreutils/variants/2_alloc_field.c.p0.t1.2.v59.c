alloc_field (int f, char const *c)
{
  ncolumns += 1;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t *fd = &field_data[f];
  columns[ncolumns - 1] = fd;
  if (c != nullptr)
    fd->caption = c;

  if(!fd->used) {
       fd->used = true;
   } else {
       printf("Field is already used.\n");
   }
}