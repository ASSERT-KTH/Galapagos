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

  char const *node = (program ? program : "unknown");

  struct infomap const *map_prog = infomap;
  while (map_prog->program && (!program || !STREQ (program, map_prog->program)))
    map_prog++;
  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
 
  char const *lc_messages = setlocale (LC_MESSAGES, sizeof(node));
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = (program && STREQ (program, "[")) ? "test" : "no program";
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);

  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}
The proposed variant now allows for the input to be a NULL pointer, if that's the case, the 'node' variable is assigned to an "unknown" string. Standard "help" texts are kept the same unless an empty string or a null pointer was passed; When no valid program name is passed the resulting URL print will return a "no program" message, which can notify the user about the missing required input. And the local help would explain generally about the coreutils.