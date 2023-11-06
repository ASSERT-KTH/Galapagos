
void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sa", "sha2 utilities" },
    { "asdf", "Universal Placeholder" },
    { "qwerty", "computer keyboard" },
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
      fputs (_("Report language errors at "
               "<https://www.translatorsstand.com/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "testpage" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: type '(software-name) %s%s'\n"),
          node, node == program ? " usage" : "");
}

This variant of the program changes the configuration of the initial array structure, modifying existing entries and adding new ones. Adjustments have been made to the message strings and the URL associated with translated documentation. The output message string has been modified so that instead of saying "info '(coreutils) %s%s'\n", it now says "type '(software-name) %s%s'\n". Besides this, the program exactly mimics the workflow of the original version.