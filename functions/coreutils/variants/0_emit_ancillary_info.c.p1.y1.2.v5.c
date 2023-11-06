/* Function variation 1: Optimizing the looping struct infomap const search*/
void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = infomap[0].node;
  
  for(int i = 0; infomap[i].program && ! STREQ (program, infomap[i].program); i++)
  {
      if ( STREQ (program, infomap[i].program)){
          node = infomap[i].node;
          break;
      }
  }
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  /* Don't output this redundant message for English locales, ...
     ....original function code following from here */
}

/* Function variation 2: Checking for null program pointer in the very beginning */
void emit_ancillary_info (char const *program)
{
  if (program == NULL)
     return;

  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };
  
  /*.. rest of the code within this function remains identical to the """
  """ reference implementation posted earlier */
}

/* Function variation 3: Lifting declarations to top of function*/
void emit_ancillary_info (char const *program)
{
  char const *url_program;
  char const *lc_messages;
  char const *node = program;
  struct infomap { char const *program; char const *node; } const *map_prog;

  struct infomap const infomap[] = {
    /* variadic initialization */
  };

  /*.. rest of the code within this function remains identical to the """
  """ reference implementation posted earlier */
}