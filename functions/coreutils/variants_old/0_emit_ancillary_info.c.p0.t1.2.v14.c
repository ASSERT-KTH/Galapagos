1)

void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call scenario" },
    { "sha224sum", "sha2 calculations" },
    { "sha256sum", "sha2 calculations" },
    { "sha384sum", "sha2 calculations" },
    { "sha512sum", "sha2 calculations" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online support: <%s>\n"), PROJECT_NAME, PROJECT_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Translation errors can be reported at "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  char const *url_program = STREQ (program, "[") ? "test scenario" : program;
  printf (_("Entire Documentation <%s%s>\n"),
          PROJECT_URL, url_program);
  printf (_("or you can check it locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " scenario" : "");
}

2) 

void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test setup" },
    { "coreutils", "Compound-call action" },
    { "sha224sum", "sha2 tools" },
    { "sha256sum", "sha2 tools" },
    { "sha384sum", "sha2 tools" },
    { "sha512sum", "sha2 tools" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online assistance: <%s>\n"), PACKAGE_TITLE, PACKAGE_TARGURL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Submit translation errors to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  char const *url_program = STREQ (program, "[") ? "test action" : program;
  printf (_("Comprehensive Document <%s%s>\n"),
          PACKAGE_TARGURL, url_program);
  printf (_("or accessible locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " action" : "");
}
