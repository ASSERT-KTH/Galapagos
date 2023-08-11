1. Variant by changing transient text in printf method

This variant changes the transient text in printf, fputs method statements without affecting the logic of the code.


void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    {"[", "Change Invocation"},
    {"coreutils", "Instead of Multi-call invocation"},
    {"sha224sum", "Alternative sha2 utilities"},
    {"sha256sum", "Alternative sha2 utilities"},
    {"sha384sum", "Alternative sha2 utilities"},
    {"sha512sum", "Alternative sha2 utilities"},
    {nullptr, nullptr},
  };   

  char const *node = program;
  struct infomap const *map_prog = infomap;

   while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;  

  printf (_("\n%s see this helpful online resource: <%s>\n"), PACKAGE_NAME, PACKAGE_URL); 

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);

  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
  {
      fputs (_("Redirect any bug related translations to this address "
               "<https://redirect-bug.project.org/>\n"), stdout);
  }

  char const *url_program = STREQ (program, "[") ? "test" : program; 

  printf (_("Extension of documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("Or access it locally through: info '(extension) %s%s'\n"),
            node, node == program ? "Begin Invocation" : ""); 
}


2. Variant by re-order code lines

This variant by swapping a few lines in the function so that it acts a bit differently, but doesn't change the original functionality of the program.


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

  struct infomap const *map_prog = infomap;
  
  while(map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;
    
  char const *node = map_prog->node? map_prog->node : program;
  
  printf(_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
  char const *lc_messages = setlocale(LC_MESSAGES, nullptr);

  if(lc_messages && STRNCMP_LIT(lc_messages, "en_"))
    fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);

  char const *url_program = STREQ (program, "[") ? "test" : program;

  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");  
}
