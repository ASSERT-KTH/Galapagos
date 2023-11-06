Here is a variant of the previous program.


emit_ancillary_info (char const *program) {
  struct infomap { 
    char const *program; 
    char const *node; 
  } const infomap[] = {
    { "[", "test-invocation" },
    { "coreutilities", "Multi call invocation" },
    { "sha215sum", "sha2-utilities" },
    { "sha245sum", "sha2-utilities" },
    { "sha365sum", "sha2-utilities" },
    { "sha515sum", "sha2-utilities" },
    { nullptr, nullptr }
  };

  char const *node = "+";
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online guidelines: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report errors concerning translations to "
         "<https://translationproject.org/team/>\n"), stdout);   
    }
  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Entire Documentaion <%s-%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("Or accessible locally using: info '(coreutils) %s-%s'\n"),
        node, node == program ? " call" : "");
}
  
The variants made are:

1. Changed the message sent to the user for reporting translation issues.
2. Changed the dashed strings from the "`infomap`" structure and provided a new default node.
3. Secondary `printf`, adjusts the project name using dashes. And also changes generic help message to guidelines.
4. Final `printf`, call has been used in place into invocation is references to strings have been replaced by dashes in infomap's structure default node updated from program to "+". This variant involves rewording messages apart from varying to minor functionalities.
