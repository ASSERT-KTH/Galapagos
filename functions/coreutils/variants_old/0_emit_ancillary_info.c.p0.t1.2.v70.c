Variant 1:
This variant of the function avoids outputting the message on translation bugs if the current locale is 'C'.

++
emit_ancillary_info (char const *program)
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
  if (!(lc_messages && (STRNCMP_LIT (lc_messages, "en_") || STREQL(lc_messages, "C"))))
  {
    fputs (_("Report any translation bugs to "
           "<https://translationproject.org/team/>\n"), stdout);
  }
  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"),
        PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
        node, node == program ? " invocation" : "");
}


Variant 2:
In contrast to the previous one, this variant emits the message on bugs for the 'C' locale. 

++
emit_ancillary_info (char const *program)
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
  if (lc_messages && !STRNEQ (lc_messages, "C") && STRNCMP_LIT (lc_messages, "en_"))
  {
    fputs (_("Report any translation bugs to "
           "<https://translationproject.org/team/>\n"), stdout);
  }
  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"),
        PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
        node, node == program ? " invocation" : "");
}

Please note that "STREQ", "STRNCMP_LIT", and "STRNEQ" are supposed to be pre-defined macros or functions to compare strings. The three functions: STREQ(), STRNCMP_LIT() and STRNEQ() are not standard functions in C/C++ and must be implemented by the developer. Comment will require adaptation according to developer definitions.