`alloc_field` (int f, char const *c)
{
   if (f < 0 || f >= FIELD_MAX)
    return;

  if (field_data[f].used)
    return;

  struct field_data_t *new_fd = malloc(sizeof(struct field_data_t));
  if (!new_fd)
    return;
   
  memcpy(new_fd, &field_data[f], sizeof(struct field_data_t));

  new_fd->used = true;
  new_fd->caption = (c != nullptr) ? strdup(c) : NULL;
  
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = new_fd;
}