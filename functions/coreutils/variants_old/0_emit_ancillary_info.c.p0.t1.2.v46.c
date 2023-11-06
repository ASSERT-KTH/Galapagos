Variant 1: A complete copy of additional information is produced before output.
++
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

  char display_package[100];
  sprintf(display_package, "\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL);
  printf(_(display_package));

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      char message[250];
      sprintf(message, "Report any translation bugs to "
               "<https://translationproject.org/team/>\n");
      fputs (_(message), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  
  char doc_message[200];
  sprintf(doc_message, "Full documentation <%s%s>\n",
          PACKAGE_URL, url_program);
  printf (_(doc_message));

  char info_message[200];
  sprintf(info_message, "or available locally via: info '(coreutils) %s%s'\n",
          node, node == program ? " invocation" : "");
  printf (_(info_message));
}


Variant 2: Force language setting to non-english, where translation notification will always be shown to the users.
++
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

  setlocale (LC_MESSAGES, "fr_FR");
  
  fputs (_("Report any translation bugs to "
           "<https://translationproject.org/team/>\n"), stdout);

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}
