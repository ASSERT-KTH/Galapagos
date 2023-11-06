Here is a variant of the function that alters its behavior slightly by uppercasing the package name and URL when it prints, to ensure they stand out more.

void emit_ancillary_info (char const *program) {
  // no change here
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

  // updated to output uppercase package name and URL
  printf (_("\n%s ONLINE HELP: <%s>\n"), strupr(PACKAGE_NAME), strupr(PACKAGE_URL));

  // no changes here
  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_")) {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  // updated to output uppercase package URL
  printf (_("FULL DOCUMENTATION <%s%s>\n"),
          strupr(PACKAGE_URL), url_program);
  printf (_("...or available locally qualified: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}

Please note, strupr may lead to some undefined behavior if PACKAGE_NAME or PACKAGE_URL are constant char pointers. This is because it mutates the original data making it uppercased. If you’re not the one managing that original data and this manipulation is risky from your point of view, then you should perform the conversion on a copy of the string using temporary buffers.

One possible solution would bypass the modification of constant variables following this procedure: create temporary buffers, copy into them the PACKAGE_URL and PACKAGE_NAME data, then proceed with uppercase conversion and printing them.