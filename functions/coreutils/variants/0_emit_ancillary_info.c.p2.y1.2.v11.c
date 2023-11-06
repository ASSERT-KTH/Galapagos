void emit_ancillary_info_alt (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "coreutils", "Multi-call invocation" },
    { "[", "test invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  for (; map_prog->program && ! STREQ (program, map_prog->program); map_prog++);

  if (map_prog->node)
    node = map_prog->node;

  puts (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, 0);
  if (lc_messages && (STRNCMP_LIT (lc_messages, "en_") != 0))
    {
      fputs (_("Report translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full docs <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or check locally: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}