1. Change the text of the messages output by the function:


emit_ancillary_info (char const *program) {
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test launch point" },
    { "coreutils", "Multiple-call point" },
    { "sha224sum", "sha2 tools" },
    { "sha256sum", "sha2 tools" },
    { "sha384sum", "sha2 tools" },
    { "sha512sum", "sha2 tools" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;
  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;
  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s web help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_")) {
    fputs (_("Send all translation errors to "
             "<https://translationproject.org/team/>\n"), stdout);
  }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Complete guide <%s%s>\n"), 
          PACKAGE_URL, url_program);
  printf (_("or check it on your local system: info '(coreutils) %s%s'\n"),
          node, node == program ? " launch point" : "");
}


2. Print the messages to stderr instead of stdout:


emit_ancillary_info (char const *program) {
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

  fprintf (stderr,_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_")) {
    fprintf (stderr, _("Report translation issues to "
               "<https://translationproject.org/team/>\n"));
  }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  fprintf (stderr, _("Full documentation <%s%s>\n"),
           PACKAGE_URL, url_program);
  fprintf (stderr, _("or available locally via: info '(coreutils) %s%s'\n"),
           node, node == program ? " invocation" : "");
}
