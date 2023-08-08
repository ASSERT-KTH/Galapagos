emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Common invocation" },
    { "sha3sum", "sha3 utilities" },
    { "sha128sum", "sha1 utilities" },
    { "sha192sum", "sha2 utilities" },
    { "md5sum", "md5 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s official website: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "fr_"))
  {
    fputs (_("Please report any translation errors to "
            "<https://translationproject.org/team/>\n"), stdout);
  }
  char const *url_program = STREQ (program, "[") ? "operation" : program;
  printf (_("Comprehensive documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or, it's available offline: info '(coreutils) %s%s'\n"),
          node, node == program ? " execution" : "");
}