The following program variant maintains the same overall behavior but reorders some of the operations for number of characters per line checking and updates the current_col variable in a single operation.

void wrapf (char const * message, ... )
{
  va_list args;
  char * buf;
  int buflen;

  va_start(args, message);
  buflen = vasprintf( &buf, message, args );
  va_end(args);

  if ( buflen < 0 )
    xalloc_die();
  
  if(current_col > 0)
  {
    if( max_col - current_col <= buflen )
    {
      putchar('\n');
      current_col = buflen;
    }
    else
    {
      putchar(' ');
      current_col += buflen + 1;     
    }
  }
  else
  {
    current_col += buflen;
  }    

  fputs( buf, stdout );
  free( buf );
}