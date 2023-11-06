1. Translation Message Incorporation:


emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "leftbracket", "test invocation" },
    { "utils_base", "Multi-call invocation" },
    { "sha2_224", "sha2 utilities" },
    { "sha2_256", "sha2 utilities" },
    { "sha2_384", "sha2 utilities" },
    { "sha2_512", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("%s helpdesk: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Send us your translation errors at "
               "<https://translationproject.org/team>\n"), stdout);
    }

  char const *url_program = STREQ (program, "leftbracket") ? "bracket-test" : program;
  printf (_("Detailed Manual <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("locally: info '(utils_base) %s%s'\n"),
          node, node == program ? " function" : "");
}

2. Changing Conditional Order:


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

  char const *node = program;
  struct infomap const *map_prog = infomap;
  char const *url_program = STREQ (program, "[") ? "test" : program;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node && STREQ(url_program, program) == false)
    node = map_prog->node;

  printf (_("\n%s online support: <%s%s>\n"),
          PACKAGE_NAME, PACKAGE_URL, url_program);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (! (lc_messages && ! STRNCMP_LIT (lc_messages, "en_")))
    {
      fputs (_("Report translator bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  printf (_("or access locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " user_guide" : "");

  printf (_("Comprehensive documentation at <%s>\n"), PACKAGE_URL);

}
