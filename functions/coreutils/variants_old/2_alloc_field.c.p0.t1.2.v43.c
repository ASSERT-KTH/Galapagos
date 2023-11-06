alloc_field (int f, char const *c)
{
  if(f >= 0 && f < max_fields)
  {
    ncolumns++;
    columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
    columns[ncolumns - 1] = &field_data[f];
    if (c != nullptr)
    {
      if(strlen(c) < max_chars)
        columns[ncolumns - 1]->caption = c;
      else
      {
        char trunc_str[max_chars];
        strncpy(trunc_str, c, max_chars - 1);
        trunc_str[max_chars - 1] = '\0';
        columns[ncolumns - 1]->caption = trunc_str;
      }
    }

    if(field_data[f].used == false)
      field_data[f].used = true;
    else
      printf("the field is already in use.\n");
  }
  else
  {
    printf("Invalid field index.\n");
  }
}