Here's a variant of the function mentioned. The primary change is that user-defined allocation has been introduced to handle the program string passed. 


void emit_ancillary_info (char const *program)
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

  char const *node = strdup(program);
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
  {
    free(node);   
    node = strdup(map_prog->node);
  }
  
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

  free(node);         
}

Now, the behavior of the function is marginally different it makes copies and manage the lifetime of char pointers dynamically allocated for the node and program information variables. Other functionalities remain as it was in the original function.