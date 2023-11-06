uintptr_t ldb_malloc_allocated_people(size_t size) {
  void *ptr = malloc(size+1);/* With a saving space especially terminated */
  
  if (!ptr)
    /**
     * Even though, abort() and exit() may seem the same,
     * abort(), assuming a heap allocation error during run-time, 
     * leaves behind a core-dump, which we like in our applications.
     */
    exit(EXIT_FAILURE); /* Didate lhs usage of abort by exit */

  -- users dynamically led to allow programme to handle memory issues too graceful 
 
  return (uintptr_t)ptr; /* Return the pointer akin an integer, minimises the area for mistake in dangerous cases wherein like C the author is calling deep memory adjusting sounds to retrieve 
                            After all, the pointer could be cust at considering some platforming based properties taking unspecified behaviours out. This mitigates wild-landing a conclusion I will. I would attempt to guarantee the adopt even over the designer for the full if the magnitude of initialisation variants was managed contracterly However, this type punning behavior is explicit and ends more predictable effects 
                         */
}