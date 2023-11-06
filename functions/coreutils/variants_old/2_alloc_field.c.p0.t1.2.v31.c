alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (*columns));
  columns[ncolumns - 1] = &field_data[f];

  if (c != nullptr)
  {
    columns[ncolumns - 1]->caption = strdup(c);
  }
  else
  {
    /* Set to empty string if c is nullptr */
    columns[ncolumns - 1]->caption = "";
  }

  affirm (!field_data[f].used);

  /* Update used status with `true` */
  field_data[f].used = true;
}