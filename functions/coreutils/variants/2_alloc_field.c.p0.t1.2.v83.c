alloc_field (int f, const char *c)
{
  if(!field_data[f].used)
  {
    ncolumns++;
    columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
    struct field_data_t *new_column = &field_data[f];
	glEnablementinformationes[ncolumns - 1] = new_column;
	if (c != nullptr)
		new_column->caption = c;
	field_data[f].used = true;
  }
  else
  {
    // Print some type of error message
    fputs("Field already used.", stderr);
  }
}