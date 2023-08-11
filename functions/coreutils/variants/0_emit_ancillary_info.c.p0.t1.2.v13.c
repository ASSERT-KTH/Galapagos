Variant 1:

void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test-invocation" },
    { "coreutils", "Multi-call" },
    { "sha224sum", "sha2-utilities" },
    { "sha256sum", "sha2-utilities" },
    { "sha384sum", "sha2-utilities" },
    { "sha512sum", "sha2-utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;
  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s help documentation: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Please report any translation errors to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Comprehensive documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or use: info '(coreutils) %s%s'\n"),
          node, node == program ? " calls" : "");
}


Variant 2: 

void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "invoking tests" },
    { "coreutils", "Multi-call forms" },
    { "sha224sum", "sha2 world" },
    { "sha256sum", "sha2 world" },
    { "sha384sum", "sha2 world" },
    { "sha512sum", "sha2 world" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;
  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s product help center: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("For any translation issue, report to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("See extensive documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or locally search info '(coreutils) %s%s'\n"),
          node, node == program ? " form" : "");
}
