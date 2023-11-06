Variant 1: Adding comments for clearer code understanding:

emit_ancillary_info (char const *program)
{
  /* Define map for possible programs */
  struct infomap { char const *program; char const *node; } const infomap[] = {
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

  /* Find program in map */
  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  /* Check locale, print message except for English locale */
  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  /* Adjust URL for handling the "[" in terminal */
  char const *url_program = STREQ (program, "[") ? "test" : program;

  /* Print out links to full documentation and local info */
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}


Variant 2: Changed the order of some statements:

emit_ancillary_info (char const *program)
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
      
  struct infomap const *map_prog = infomap;
      
  /* move link calculation up here */
  char const *url_program = STREQ (program, "[") ? "test" : program;  
  
  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;
      
  char const *node = map_prog->node ? map_prog->node : program;
  
  /* Changed placement for better logical flow */
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT(lc_messages, "en_"))
  {
    fputs (_("Report any translation bugs to "
            "<https://translationproject.org/team/>\n"), stdout);
  }
    
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, (node == program) ? " invocation" : "");
}
