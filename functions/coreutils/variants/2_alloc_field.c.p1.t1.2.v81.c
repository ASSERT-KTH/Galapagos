Here is a program variant that adds an ability to keep track counts of calls for each field. This variant contains a static integer array `field_usages`, with counts for each field stored at index same as field's index. The array is incremented in the function for `f` index when f is used.

Code goes like:

void alloc_field(int f, char const* c)
{
  static int field_usages[MAX_FIELD] = {0};  /* For simplicity
                                                 let's assume we know max fields */

  ncolumns++;
  columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t*));
  columns[ncolumns - 1] = &field_data[f];

  /* Increment the field usage */
  field_usages[f]++;

  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;
  
  /* Continue with the same behavior as before */
  assert(!field_data[f].used);
  
  /* Mark field as used. */
  field_data[f].used = true;
}

In this variant, `field_usages` can be used in your further explorations/debugging statistics (in case of studies where "how many times each usage" is required to understand some behavior etc.) Note that the use of this added feature does not impact the normal behavior of the function.