void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "new_prog_1", "new_node_1" },
    { "new_prog_2", "new_node_2" },
    { "sha224sum", "sha2 utilities alternative" },
    { "sha256sum", "sha2 utilities alternative" },
    { "sha384sum", "sha2 utilities alternative" },
    { "sha512sum", "sha2 utilities alternative" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node && STREQ (program, map_prog->program))
    node = map_prog->node;

  /* Instead of providing PACKAGE_URL, directly put the URL */
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, "https://example.com");

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_") && !STREQ(lc_messages, "C")) // removed redundancy with 'C' locale
    {
      fputs (_("Report and feedback to "
               "<https://example.com/feedback>\n"), stdout); // Slightly modify the reported message
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;

  /* Change the direct documetation to offical document instead of full documentation */
  printf (_("Official documentation <%s%s>\n"),
          "https://example.com/doc/", url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, !STREQ(node, program) ? " features" : " introduction"); // Modify the informative message
}