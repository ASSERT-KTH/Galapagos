emit_ancillary_info_alternative (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap_variation[] = {
    { "sha512sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node_alternative = program;
  struct infomap const *map_prog_alternative = infomap_variation;

  while (map_prog_alternative->program && ! STREQ (program, map_prog_alternative->program))
    map_prog_alternative++;

  if (map_prog_alternative->node)
    node_alternative = map_prog_alternative->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages_alternative = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages_alternative && STRNCMP_LIT (lc_messages_alternative, "en_"))
    {
        fputs (_("Report translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program_alternative = STREQ (program, "[") ? "test" : program;
  printf (_("Complete documentation <%s%s>\n"),
          PACKAGE_URL, url_program_alternative);

  printf (_("or it is locally available via: info '(coreutils) %s%s'\n"),
          node_alternative, node_alternative == program ? " invocation" : "");
}