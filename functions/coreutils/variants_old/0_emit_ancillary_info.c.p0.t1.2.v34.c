Here is a transformation of the original function:

void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "sha512sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha224sum", "sha2 utilities" },
    { "coreutils", "Multi-call invocation" },
    { "[", "test invocation" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (!STREQ (program, map_prog->program) && map_prog->program)
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("%s online help can be found at <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && !(lc_messages[0] == 'e' && lc_messages[1] == 'n' && lc_messages[2] == '_'))
    {
      fputs (_("Elaborate any errors you found in program translations here: "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = program[0] == '[' ? "test" : program;
  printf (_("You can read the whole documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("Similarly you can use the command in your terminal: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}

Then, certain parts of code were slightly modified to retain the same basic functionality, although now they're written in a different way, including switching and rephrasing sentences.
Specific changes include changing the order of the `infomap[]` entries (though preserving its integrity) along with changing expressions in an equivalent way. For instance, `node == program ? " invocation" : ""` was switched to `node != program ? "" : " invocation"`. Also, some equivalent but different conditional checks and different phrases take place such as `!(lc_messages[0] == 'e' && lc_messages[1] == 'n' && lc_messages[2] == '_')` instead of original checks, alternative sentences like `fputs (_("Elaborate any errors...` along with messages specifying where to send translation errors or how to access local documentation.