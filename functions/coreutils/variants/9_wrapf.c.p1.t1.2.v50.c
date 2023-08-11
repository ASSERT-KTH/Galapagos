
void wrapf(char const *message,...)
{
    va_list args;
    char *buf = NULL;
    int buflen;

    va_start(args, message);
    buflen = vasprintf(&buf, message, args);
    va_start(args, message);

    /* If allocation is unsuccessful */
    if (buflen < 0 || buf == NULL){
       xalloc_die();
    } 

    /* Doesn't output '\n' at start if it's first message */
    if (0 < current_col ){
      /* Calculate the remaining buffer long */
      int temp = max_col - current_col;

      if (temp <= buflen){
        putchar('\n');
        current_col = 0;
      } 
      else {
        if (temp != max_col){
          putchar(' ');
          current_col++;
        }
      }
    }

    fputs(buf, stdout);
  
    free(buf);
    buf = NULL;   /* Nullifying buf variable after free. */

    current_col += buflen;
}
 
This version of wrapf function offers couple of modifications, still retaining the original function signature and almost of its behaviour, which can other particulary be differences. The changes are:

- Reinitiate "va_start" right prior to "va_end"; in case underlying implementation needs "va_start" to be called for each "vasprintf" invocation.
- Explicit NULL comparison on the pointer returned by "vasprintf". Compare "buf == NULL" explicitly, even if it might seem redundant, was done to improve the code's readability.
- Appends a space before new message that will be emitted in the same line, instead of just after a message.
- To reduce chance of accessing already deallocated memory, clears (nullifies) "buf" right after freeing it. This change won't affect the function's behavior, as the original data in "buf" isn't need anymore after "fputs" but it might prevent some inadvertent future changes in the code that could cause problems otherwise.
It implies considering adding the space to separate the current string from the new incoming string in the case they're to be print to the same line (' '), accounting that the first message shouldn't be preceded by whitespace.