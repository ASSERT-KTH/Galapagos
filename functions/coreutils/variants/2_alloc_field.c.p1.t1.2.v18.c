Sure, I can provide you with a variant that doesn't change the output or result of the function whilst changing some aspect of behavior under the hood. Instead of reallocating memory array one by one with each increment, the variant function pre-allocate a certain size of array and only perform re-allocation when the size is not enough.

Here is one such variant:


#define INITIAL_SIZE 10 // Predefined arbitrary size
#define GROWTH_FACTOR 2 // Factor for expanding array size

void alloc_field (int f, char const *c) 
{
  static int allocated_size = 0;
  
  if (ncolumns >= allocated_size) 
  {
    allocated_size = allocated_size > 0 ? allocated_size * GROWTH_FACTOR : INITIAL_SIZE;
    columns = xnrealloc (columns, allocated_size, sizeof (struct field_data_t *));
  }

  columns[ncolumns] = &field_data[f];
  ncolumns++;

  if (c != nullptr) 
  {
    columns[ncolumns - 1]->caption = c;
  }

  affirm (!field_data[f].used);

  /* Mark field as used. */
  field_data[f].used = true;
}


This variant modifies the memory allocation approach: Instead of always reallocating a larger array whenever a new column needs to be added, it uses a size variable `allocated_size` to keep track of the current allocated size of the array, and only enlarges the array by a constant factor (represented by `GROWTH_FACTOR`) when `ncolumns` reaches `allocated_size`. Also, it adds an initialization value `INITIAL_SIZE` which dimensions the array at the current allocation when the array size is zero. 

It achieves the same functionality as the original function with more efficient memory allocation in case of larger input data. Although, there might likely be unused memory space allocated but would save time by calling less frequent realloc() when dealing with a large amount data.