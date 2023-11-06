emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Utilities multi-call" },
    { "sha224sum", "utility of sha2" },
    { "sha256sum", "utility of sha2" },
    { "sha384sum", "utility of sha2" },
    { "sha512sum", "utility of sha2" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\nInformation for %s found at: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STREQ (lc_messages, "en_US"))
    {
      fputs (_("Report translation issues to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  char const *url_program = !STREQ (program, "[") ? "test" : program;
  printf (_("Complete documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("Locale information: info '(coreutils) %s%s'\n"),
          node, node == program ? " execution" : "");
}