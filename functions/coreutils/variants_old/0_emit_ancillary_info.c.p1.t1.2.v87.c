You can modify the function to add a log message when the "Program" being searched in the infomap is not found:


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

  char const *node = program;
  struct infomap const *map_prog = infomap;
  bool program_found = false;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if(map_prog->program)
    program_found = true;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

   char const *url_program = STREQ (program, "[") ? "test" : program;
   printf (_("Full documentation <%s%s>\n"),
           PACKAGE_URL, url_program);
   printf (_("or available locally via: info '(coreutils) %s%s'\n"),
           node, node == program ? " invocation" : "");

   if (!program_found)
     printf ("Program %s was not found in infomap.\n", program);
}


In this modification, a boolean variable "program_found" was introduced, it's used to keep track of whether or not the program was found in the `infomap` array during the while loop. If it wasn't found, an appropriate log message gets outputted via `printf` at the end of the function. This modifies the behavior slightly by introducing potentially new output while preserving the original functionality.