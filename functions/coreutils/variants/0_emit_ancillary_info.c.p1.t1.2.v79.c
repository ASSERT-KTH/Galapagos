emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "section:test_invocation" },
    { "coreutils", "section:Multi-call_invocation" },
    { "sha224sum", "section:sha2_utilities" },
    { "sha256sum", "section:sha2_utilities" },
    { "sha384sum", "section:sha2_utilities" },
    { "sha512sum", "section:sha2_utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program)){
    map_prog++;
}

  if (map_prog->node) {
    node = map_prog->node;
}

  printf (_("\n%s online documentation: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_all_locale = getenv ("LC_ALL");
  if (lc_all_locale && STRNCMP_LIT (lc_all_locale, "en_")) {
    fputs (_("If you encounter language discrepancies, please refer to "
             "<https://translationproject.org/team/>\n"), stdout);
}

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Primary documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  
  printf (_("For further clarification, refer locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? "_explanation" : "");
}