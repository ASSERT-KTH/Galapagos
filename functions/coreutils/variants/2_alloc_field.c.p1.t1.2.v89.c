
alloc_field (int f, char const *c)
{
  /* Instead of only incrementing ncolumns once, we can add a check to avoid reallocating each time alloc_field is called.
     A multiple increase of ncolumns can potentially optimize performance. */

  if (ncolumns == 0 || ncolumns%10 == 0) 
  {
    ncolumns += 10;
    columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  }
  else
  {
    ++ncolumns;
  }

  columns[ncolumns - 1] = &field_data[f];

  //Here, instead of another direct check, we take c=NULL as an indication for an empty caption
  columns[ncolumns - 1]->caption = c ? c : "";
  
  /* Here it safer to not only check if field was not used before but return an error if the case, 
     as to indicate any repeated use of a certain field. */
  if (field_data[f].used) {       
    printf("Field already in use.\n");
    return;
  }

  /* Mark field as used.  */
  field_data[f].used = true;
}
