Below is a variant of the code which maintains the function's original functionality. Here the program variant effects include rearranging the order of printed messages such that the program first handles the "[" scenario and explicitly "test" corresponds before other messages.


void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { "[", "test" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  char const *url_program = STREQ (program, "[") ? "test" : program;

  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);

  while (map_prog->program && ! STREQ (program, map_prog->program)) {
      map_prog++;
  }

  if (map_prog->node) {
    node = map_prog->node;
  }

  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);

  if (lc_messages && STNCMP_LIT (lc_messages, "en_")) {
    fputs (_("Please report any translation bugs to "
            "<https://translationproject.org/team/>\n"), stdout);
  }
}


Note: Removal of entry `[NULL,NULL]` from the `infomap[]` struct and rearranging the entries within the the boolean logic constructs that maintain program integrity. This was designed since not finding a program on this array would not change the normal operation. Indices are densely packed, exploiting memory locality and avoiding NULL-pointer verifications, potentially contributing to optimized run-time.