void alloc_field (int f, char const *c)
{
  columns = (struct field_data_t **)realloc(columns, (++ncolumns) * sizeof(struct field_data_t *));
  if (columns == nullptr)
  {
     fprintf (stderr, "Memory allocation failed!\n");
     exit (EXIT_FAILURE);
  }

  columns[ncolumns - 1] = &field_data[f];

  if (c != nullptr)
    strcpy(columns[ncolumns - 1]->caption, c);
    
  if(field_data[f].used)
  {
    fprintf(stderr, "Field already used!\n");
    exit(EXIT_FAILURE);
  }

  /* Mark field as used.  */
  field_data[f].used = true;
}
Answering:
The code above represents a variant that changes the behavior of the original function while maintaining its original functionality.
1. Parse and use 'reallocation logic directly' in the program using 'realloc' instead of 'xnrealloc' with the new memor\xy checking.
2. Strings handling function 'strcpy' added managing substrings than simply assigning.
3. System-specific functionality to output failure reports and block further process.
4. Assert-related logic reversed and included into a significant, 'output the reason, and exit process' duo-function.
The alloc_field function is still safely executable in combination where xnrealloc, affirm, and related resources are unavailable or untrusted.
As required, auxiliary functions not created, and delegation of labor same kept. The function property: 'takes in an integer and constant char pointer and returns void,' maintained, no alterations.