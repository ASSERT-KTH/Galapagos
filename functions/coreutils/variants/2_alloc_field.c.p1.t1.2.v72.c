One way to keep the original functionality while changing behavior could be to add some conditional checks, logging activities or make the code a bit more efficient. Let's add an early return to make our code fail early when input 'f' references a field also used somewhere that was already marked used.

   Here's the variant:


alloc_field (int f, char const *c)
{
  /* Check if the field_data 'f' is already used, return early if that's the case */
  if (field_data[f].used) 
  {
    printf("Error: Field data is already in use!\n");
    return;
  }

  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];

  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;

  /* No need to check for field_data being used - we did that when we came in our function */

  /* Mark field as used.  */
  field_data[f].used = true;
}


The major difference in the above variant is that, we're returning early if the chosen field_data element is already in use. This avoids unnecessary memory (and potentially CPU) usage caused by reallocating the columns.