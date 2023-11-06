void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "[", "testing invocation" },
    { "sha256sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  struct infomap const *map_prog = infomap;
  char const *node = program;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s web reference: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  char const *url_program = STREQ (program, "[") ? "testing" : program;

  printf (_("Reference files <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("Accessible locally via: info '(coreutils) %s%s'\n"), 
          node, node == program ? " command" : "");
  
  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT(lc_messages, "en_")) {
      fputs (_("For any language related issues "
               "<https://translationproject.org/language/>\n"), stdout);
    }
}