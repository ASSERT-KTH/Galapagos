int alloc_field (int f, char const *c)
{
  struct field_data_t * temp; 

  /* Allocate extra space in 'columns'. */
  temp = (struct field_data_t *)realloc(columns, (ncolumns+1) * sizeof(struct field_data_t *));
  if (temp)
  {
    columns = temp; 
  }
  else
  {
    perror("Cannot allocate more space in 'columns'!\n");
    return -1; 
  }

  /* Set last element to address of field_data[f]. */
  columns[ncolumns++] = &field_data[f]; 

  /* If caption string exists, copy it to 'columns' data. */
  if (c)
  {
    columns[ncolumns - 1]->caption = (char *)malloc((strlen(c) + 1) * sizeof(char));
    if (columns[ncolumns - 1]->caption)
    {
      strcpy(columns[ncolumns - 1]->caption, c); 
    }
    else
    {
      perror("Cannot allocate memory for caption in 'columns'!\n");
      return -1; 
    }
  }

  if (field_data[f].used) 
  {
    fputs("Field already used!\n", stderr);
    return -1; 
  }

  /* Mark field as used. */
  field_data[f].used = true;

  return 0; 
}