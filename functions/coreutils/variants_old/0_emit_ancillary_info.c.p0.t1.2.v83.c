Here's an example for a transformation:


emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "alternative test invocation" },
    { "coreutils", "Alternate Multi-call invocation" },
    { "sha224sum", "revised sha2 utilities" },
    { "sha256sum", "revised sha2 utilities" },
    { "sha384sum", "revised sha2 utilities" },
    { "sha512sum", "revised sha2 utilities" },
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
      fputs (_("Please kindly refer any translation inconsistencies to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  
  char const *url_program = STREQ (program, "[") ? "normal_test" : program;
  printf (_("Consult the full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("Alternatively, refer to local info: info '(coreutils) %s%s'\n"),
          node, node == program ? " activation" : "");
}

In this variant, the descriptions of the programs are updated to make them visit different documentation pages or have alternate responses if they hit the corresponding case. The messages sent to the terminal are also changed slightly, however, the fundamental idea or operation of the program is not modified and the structure of the blocks is maintained.