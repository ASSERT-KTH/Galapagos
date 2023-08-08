emit_ancillary_info (char const *program)
{
  struct infomap
  { 
    char const *program; 
    char const *node; 
  } const infomap[] = {
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

  for(;map_prog->program; ++map_prog)    // replace of while loop with an equivalent for loop
  {
    if(STREQ (program, map_prog->program))
    break;
  }

  if (*map_prog->program) // verification of non-nullability of map_prog->program
    node = map_prog->node;
  
  printf (_("\nUpdated %s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);   // added word "Updated" to the existing

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages ? STRNCMP_LIT (lc_messages, "en_") : 0 ) // ternary operator for same operation to ensure lc_messages non-null
  {
    fputs (_("Kindly report any translation bugs to : "
                "<https://translationproject.org/team/>\n"), stdout);   // modify the line giving better understanding for bug report
  }

  char const *url_program = (program == nullptr) ? "none" : STREQ (program, "[") ? "test" : program; //Added check for NULL program

  printf (_("Changed Full documentation available <%s%s>\n"),
          PACKAGE_URL, url_program);  // slight modification in printf statement
  printf (_("If not found check locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");  // Modify Output line  for locally checking information
}