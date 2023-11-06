Here's a variant implementation of the function: 


void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "sha512sum", "sha2 utilities" },
    { "coreutils", "Multi-call invocation" },
    { "[", "test invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
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
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation available @ <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("Or, get it locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}


Compared to the original implementation, this version changes information presentation slightly: the ordering of infomaps items was reshuffled and couple of sentences were tweaked - 'Report any translation bugs...' was shortened to 'Report translation bugs...' and placeholders' replacements in 'printf' were prefixed with '@' and capitalized first letter after colon for readability improvements. Nevertheless, these changes are minimal and essentially, the functional behavior of `emit_ancillary_info` was preserved.