Here's one variant of the function that maintains its original functionality. In this variant, after incrementing number of columns and allocating memory for new column structure, I assume that the f value is not always pointing to an available field_data structure's offset. To ensure we do not assign incorrect pointers, I added a condition to check whether pointed field_data is already used or not. If it is used, then look for an unused field_data and assign its address. But, it will affect the interpretation of f argument.

In Original function, f always points to the required field_data's offset. But in this variant f will point to the required field_data only if it is unused, otherwise a new field will be calculated.

Please check if your specifications allow processing f argument value based upon its prior usage or not.

Here is the modified function.

alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  
  if (!field_data[f].used)
    columns[ncolumns - 1] = &field_data[f];
  else
  {
    for (int i = 0; i < nfield_data; ++i)
    {
        if (!field_data[i].used)
        {
            columns[ncolumns - 1] = &field_data[i];
            f = i;// Incase f value is referred later on
            break;
        }
    }
  }
  
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;
    
  affirm (!field_data[f].used);

  /* Mark field as used.  */
  field_data[f].used = true;
}


Note: The provided value of f representing a non-occupied field_info element depends upon usage of f argument in the entire function implementation where this function is utilized. If f value is strictly required to refer a fixed element in every case, it may have unwanted effects.