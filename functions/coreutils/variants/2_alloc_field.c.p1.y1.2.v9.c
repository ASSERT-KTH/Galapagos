Variant 1:

alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  
  if (c != nullptr)
  {
      columns[ncolumns - 1] = &field_data[f];
      columns[ncolumns - 1]->caption = c;
  }
  else
  {
      columns[ncolumns - 1] = &field_data[f];
  }

  if (!field_data[f].used)
      /* Mark field as used.  */
      field_data[f].used = true;
}

Variant 2:

alloc_field (int f, char const *c)
{
  ncolumns++;
  struct field_data_t *newField = &field_data[f];
  columns = xnrealloc (columns, ncolumns, sizeof (*newField));
  columns[ncolumns - 1] = newField;

  if (c != nullptr)
   {
    columns[ncolumns - 1]->caption = c;
  }

  if (!newField->used)
  {
    /* Mark field as used.  */
    newField->used = true;
  }
}


Variant 3:

alloc_field(int f, char const *c)
{
  if (!field_data[f].used)
  {
    ncolumns++;
    columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
    columns[ncolumns - 1] = &field_data[f];

    if (c != nullptr)
    {
      columns[ncolumns - 1]->caption = c;
    }

    /* Mark field as used.  */
    field_data[f].used = true;
  }
}
