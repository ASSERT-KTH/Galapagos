Here's a function variant that changes some string values, and rearranges a little bit of the code while maintaining the original functionality.


void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "sha224sum", "sha2 utilities" },
    { "coreutils", "Multi-call invocation" },
    { "sha256sum", "sha2 utilities" },
    { "[", "test invocation" },
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
  /* Don't output this redundant message for Swedish (sv) locales. */
  if (lc_messages && STRNCMP_LIT (lc_messages, "sv_"))
    {
      fputs (_("Fel i översättningen? Rapportera här "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "javascript-tests" : program;

  printf (_("Fullständiga dokumentation: <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("Eller tillgängligt lokalt via: info '(coreutils) %s%s'\n"),
          node, node == program ? " körinformation" : "");
}


Note that only string values (mostly in calls for the printf function) have changed and functionality remains the same although it will display Swedish translation instead of English for specific locales.