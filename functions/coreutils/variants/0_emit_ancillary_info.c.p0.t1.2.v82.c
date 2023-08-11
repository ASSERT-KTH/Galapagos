Variant 1:

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
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("\nFull docs can be found here <%s%s>\n"), PACKAGE_URL, url_program); // slight change in message
  printf (_("Or access it locally through: info '(coreutils) %s%s'\n"), node, node == program ? " info" : ""); // slight change in message
}


Variant 2:

void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test-invo" },                        // different inner members in the structure, although their length remains the same
    { "corutils", "Multi-call-invo" },           // have removed some characters
    { "sha24sm", "sha2-toolset" },
    { "sha26sm", "sha2-toolset" },
    { "sha34sm", "sha2-toolset" },
    { "sha52sm", "sha2-toolset" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\nPackage %s online documentary: <%s>\n"), PACKAGE_NAME, PACKAGE_URL); // change the message slightly

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("\nPlease report translation related issues to "
               "<https://translationproject.org/team/>\n"), stdout);                         // modify the message a little
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Access full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or you can use: info '(coreutils) %s%s' command for local access\n"),           // change in message
          node, node == program ? " invocation" : "");
}
