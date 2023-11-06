Here is the altered version. The changes in this version include an alternative method of iterating over the infomap array using for instead of while. Translation message has been included inside an else clause. To identify English locales 'strstr' is used instead of an enterprise specific STRNCMP_LIT.


void emit_ancillary_info (char const *program) {
  struct infomap { 
    char const *program; 
    char const *node; 
  };
  
  const struct infomap infogrid[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *mapping = infogrid;

  for (; mapping->program && strcmp(program, mapping->program) != 0; ++mapping);

  if (mapping->node)
    node = mapping->node;

  printf ("\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  
  if (lc_messages && strstr(lc_messages, "en_") != lc_messages) {
    fputs ("Report any translation bugs to "
          "<https://translationproject.org/team/>\n", stdout);
  } else {
    char const *url_program_node = !strcmp(program, "[")
        ? "test"
        : program;
  
    printf ("Full documentation <%s%s>\n",
            PACKAGE_URL, url_program_node);
    
    printf ("or available locally via: info '(coreutils) %s%s'\n",
            node, node == program ? " invocation" : "");
  }
}                                                                       
