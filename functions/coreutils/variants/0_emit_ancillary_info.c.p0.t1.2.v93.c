Consider emitting the translation bugs report information only for non-English locales:


void emit_ancillary_info (char const *program)
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

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
      char const *url_program = STREQ (program, "[") ? "test" : program;
      printf (_("Full documentation <%s%s>\n"),
              PACKAGE_URL, url_program);
      printf (_("or available locally as: info '(coreutils) %s%s'\n"),
              node, node == program ? " invocation" : "");
    }
}


The above version of `emit_ancillary_info` adds a conditional that only enters if the acquired locale is not English (“en_”). This changes the function's output in that the “full documentation” and “available locally as” messages will now be printed only when the locale is not English.