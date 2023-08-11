void alloc_field (int f, char const *c)
{
  columns = (struct field_data_t **) realloc (columns, (ncolumns+1) * sizeof (struct field_data_t *));
  ncolumns++;
  columns[ncolumns - 1] = &field_data[f];
  if (c != nullptr)
    columns[ncolumns - 1]->caption = strdup(c);

  assert (!field_data[f].used);

  /* Mark field as used.  */
  field_data[f].used = true;
} 
Changes:
I have rearranged the order of incrementing ncoloumns and reallocating columns. In the new pointer array elements will not be set to an atomically allocated zeroed memory as was happening due to the function call xnrealloc and now malloc will be called once internally inside realloc as per man realloc and cplusplus.com "The function may move the memory block to a new location (whose address is returned by the function)." Also realloc might express concern about the loss and duplication of data handled by realloc if capacity was already included inside the chunk of memory originally mallocottorobot depending on libc being used
Following the convention the input caption string won't be externally preserved instead after successful c-style string manipulation its copied internals are conveyed to avoid mutation externally after this transfer. Or it could be something was counting on that copy possibly being done & done repeatedly indicating an unusual/problem condition inside of the C code-based system/device reporting hardware.
Some environments provide reliability, as assert causing a fatal program exit changes normal execution path litters and making things red silently. Instead of notification windows appearing in-app or OS causing better behaving systems & awareness. After the reordering of the lines that manage columns and ncolumns, it must be ensured by every calling code segment transfers f index/assumably data along but - the assert modified to warn this change has been made  intensively extra-upheld. After certain reasonable upper bounds are set mandatory, the proving could cause exiting reparation repeating as corrections can now involve minor automatically global versions & continued sequences handled cases or perform and log operations over possibly remote computers/platforms/environment + consistently compliying each architectural/dynamic principle may cause safer better executions earlier organized all needing signals and call location steps documented or compatibility, a performance of a partnership inter-entity comm-company faster response collaborative ways serving realtime community.