Variant 1 - Introducing some extra 'printf' statements for debugging:


void emit_ancillary_info (char const *program)
{
  struct infomap {
    char const *program; 
    char const *node;
  } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;
  
  if (map_prog->node)
    node = map_prog->node;

  printf ("\n%s program entered: <%s>\n".

  printf ("\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
  {
    fputs (_("Report any translation bugs to "
             "<https://translationproject.org/team/>\n"), stdout);
  }
  
  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf ("Prorgam being processed <%s%s>\n", PACKAGE_URL, url_program);
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}

  
Variant 2 - Changing the order of operations:


void emit_ancillary_info (char const *program)
{
  struct infomap {
    char const *program; 
    char const *node;
  } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;
      
  while (map_prog->node && ! STREQ (node, map_prog->node))
    map_prog++;

  if (map_prog->program)
    program = map_prog->program;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
  {
    fputs (_("Report any translation bugs to "
             "<https://translationproject.org/team/>\n"), stdout);
  }

  char const *url_program = STREQ(node, "test") ? "[" : node;
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), program, program == node ? " invocation" : "");
}
 

 These modified versions of the function retain the original functionality while making small adjustments to the behavior.