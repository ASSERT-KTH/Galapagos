Function Variant 1: 
In this variant, slight modifications have been made in the if statement and added a full local document located within while maintaining the original behaviour.

++
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

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  /* Don't output this redundant message for English locales. */
  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT(lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full online documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("Full Local documentation accessible via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}

Function Variant 2: 
In this variant, instead of stating that full documentation is available. Simply prints "Visit: [URL]" also provided a variant of handling program "[":

++
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

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;
  
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
    
  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT(lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  char const *url_program;
  if (STREQ(program, "[") || STREQ (program, "coreutils"))
    url_program = "test";
  else
    url_program = program;
  
  printf (_("Visit: <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or an alternative way: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}
