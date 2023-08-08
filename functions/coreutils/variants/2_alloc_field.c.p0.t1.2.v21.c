alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  field_data[f].used = true;
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;
  else
    columns[ncolumns - 1]->caption = "No Caption";

  affirm (!field_data[f].used);

  /* No need to mark field as used here as already marked */
}
