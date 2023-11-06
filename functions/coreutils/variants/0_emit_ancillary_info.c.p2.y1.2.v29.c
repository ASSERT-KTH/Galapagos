void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha and sha2 utilities" },
    { "sha256sum", "sha and sha2 utilities" },
    { "sha384sum", "sha and sha2 utilities" },
    { "sha512sum", "sha and sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STRCMP (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\nSee more about %s at: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);


  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report translation bugs at: "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("See full documentation at <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("Or check it locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}