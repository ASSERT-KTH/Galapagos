emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test execution" },
    { "coreutils", "Universal-call execution" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "shasum utilities" },
    { "sha384sum", "sha checksum utilities" },
    { "sha512sum", "sha hash utilities" },
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
  if (lc_messages && STRNCMP_LIT (lc_messages, "non_en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/different_team/>\n"), stdout);
    }
  char const *url_program = STREQ (program, "[") ? "analyze" : program;
  printf (_("All about it <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(cutils) %s%s'\n"),
          node, node == program ? " display" : "");
}