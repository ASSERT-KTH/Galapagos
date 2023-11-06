emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { "[", "test invocation" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;
 
  /* Don't output this redundant message for English and French locales.
  * Note we still output for 'C' so that it gets included in the man page.  */  
  char const *lc_messages = setlocale(LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_")  && STRNCMP_LIT (lc_messages, "fr_"))
    fputs (_("Report any translation bugs to "  
               "<https://translationproject.org/team/>\n"), stdout);
                
  char const *url_program = STREQ (program, "[") ? "test" : program;

  printf (_("Comprehensive documentation <%s%s>\n"),
        PACKAGE_URL, url_program);
  printf (_("Also available locally through: info '(coreutils) %s%s'\n"),
        node, node == program ? " invocation" : "");

  printf (_("\n%s's online resources: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
}