emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test_i" },
    { "coreutils", "Multi-call" },
    { "sha224sum", "sha2" },
    { "sha256sum", "sha2" },
    { "sha384sum", "sha2" },
    { "sha512sum", "sha2" },
    { nullptr, nullptr }
  };

  char const *node = program; 
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s information: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Please send translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("For complete documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("Or manually via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invoke" : "");
}