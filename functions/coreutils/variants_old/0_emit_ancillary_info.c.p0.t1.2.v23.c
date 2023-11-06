Transformation 1:

void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "coreutils", "Multi-call invocation" },
    { "[", "test invocation" },
    { "sha512sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha224sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online support: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report translation bugs at: "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Detailed documentation at <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or check locally with: info '(coreutils) %s%s'\n"),
          node, node == program ? " usage" : ""); 
}

Transformation 2:

void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { "coreutils", "Multi-call invocation" },
    { "[", "test invocation" },
    { nullptr, nullptr }
  };
  
  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && STRCMP (program, map_prog->program) != 0)
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\nGet %s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Transmission bugs should be reported at "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STRCMP (program, "[") ? program : "test";
  printf (_("Full online documentation at <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or access locally through 'info "(coreutils) %s%s"'\n"),
          node, node == program ? " execution" : "");
}

