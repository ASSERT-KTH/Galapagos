Here is one possible variant of your function, which checks if the field_data has already been used:

++
alloc_field (int f, char const *c)
{
  
  if (!field_data[f].used)
  {
      ncolumns++;
      columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
      columns[ncolumns - 1] = &field_data[f];
      if (c != nullptr)
        columns[ncolumns - 1]->caption = c;

      /* Mark field as used.  */
      field_data[f].used = true;
  }

  affirm (!field_data[f].used);
}


This variant does essentially the same thing as the original, but aborts and stays silent if the field has already been used. This might help if calls to alloc_field() aren't idempotent and the function is called twice with the same parameter for some reason.