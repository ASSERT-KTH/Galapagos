alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t *new_field = &field_data[f];

  if (new_field)
    {
       if (c != nullptr)
           new_field->caption = c;

      if (!new_field->used)
      {
         /* Mark field as used.  */
         new_field->used = true;
      }
    }

   columns[ncolumns - 1] = new_field;
}