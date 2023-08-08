
alloc_field (int f, char const *c)
{
  assert(f >= 0);
  if(field_data_size <= f)
  {
    field_data = realloc(field_data, (f+1)*sizeof(struct field_data_t));
    int i;
    for(i=field_data_size; i <= f; ++i)
      field_data[i].used = false;
    field_data_size=f+1;
  }

  assert (!field_data[f].used);
  field_data[f].used = true;

  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = field_data + f;
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;
}

The difference here is that if you pass in an `f` that is larger than `field_data_size`, not only it wouldn't crash, but it also reallocates `field_data` to accommodate the new element, marking any intermediate ones as unused. Now `alloc_field` can handle larger values if your `field_data` array wasn't already set up for it.