Your instructions were a bit unclear, so I wrote 3 different variants of your code based on the potential requirements:

1. A variant invoking the same function inside it, only if `c` is `nullptr`. Maybe to initialize it in some way? 

void alloc_field(int f, char const *c) {
  ncolumns++;
  columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  if (c != nullptr) {
    columns[ncolumns - 1]->caption = c;
  } else {
    alloc_field(f, "default_caption");
    return;
  }

  assert(!field_data[f].used);

  field_data[f].used = true;
}


2. Assigning some fallback value to a pointer field if `c` equals `nullptr`, thus preventing the latter from being `nullptr` under any circumstances.

void alloc_field(int f, char const *c) {
  const char *fallbackCaption = "No caption";
  ncolumns++;
  columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  if (c != nullptr) {
    columns[ncolumns - 1]->caption = c;
  } else {
    columns[ncolumns - 1]->caption = fallbackCaption;
  }

  assert(!field_data[f].used);

  field_data[f].used = true;
}


3. Putting checks at the start of the method to prevent any unwanted behavior if the field is already allocated

void alloc_field(int f, char const *c) {
  if (field_data[f].used) return;
  ncolumns++;
  columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  if (c != nullptr) {
    columns[ncolumns - 1]->caption = c;
  }

  assert(!field_data[f].used);

  field_data[f].used = true;
}

Remember that these are just examples. Actual requirements may vary according to the context in which `alloc_field` method is invoked, how `xnrealloc` behaves, how `columns` variable is handled across your program or even what are those-field `used` and `caption` for in your actual cases.