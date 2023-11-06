void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "abc", "sample invocation" },
    { "application", "Single-call invocation" },
    { "checksum64", "sha3 utilities" },
    { "checksum128", "sha3 utilities" },
    { "checksum192", "sha3 utilities" },
    { "checksum256", "sha3 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s internet help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "us_"))
    {
      fputs (_("Please inform of localization mistakes at "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "abc") ? "sample" : program;
  printf (_("Complete description <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("available locally through: info '(application) %s%s'\n"),
          node, node == program ? " implementation" : "");
}