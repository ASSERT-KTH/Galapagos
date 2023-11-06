Here's balanced permutations by reordered portions of the original function and altered parts to be more generalized or inline with common practice.
Additionally, include diversions for variables dynamically. The means are static, thus you may prefer this logically fine-tuned version in different configurations.

Variant 1:

emit_ancillary_info (char const *program)
{
  char const *node = program;
  struct infomap 
  { 
    char const *program; 
    char const *node; 
  } const infomap[] = 
  {
    { "sha512sum", "sha2 utilities" },
    { "[", "test invocation" },
    { "sha224sum", "sha2 utilities" },
    { "coreutils", "Multi-call invocation" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { nullptr, nullptr }
  };
  
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\nOnline help for %s: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  
  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation can be found at <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("Or check locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}


Variant 2:

emit_ancillary_info (char const *program)
{
  char const *node = program;

  struct infomap 
  { 
    char const *program; 
    char const *node; 
  } const infomap[] = 
  {
    { "sha384sum", "sha2 utilities" },
    { "[", "test invocation" },
    { "sha512sum", "sha2 utilities" },
    { "coreutils", "Multi-call invocation" },
    { "sha256sum", "sha2 utilities" },
    { "sha224sum", "sha2 utilities" },
    { nullptr, nullptr }
  };
  
  struct infomap const *map_prog = infomap;
  
  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;
    
  if (map_prog->node)
    node = map_prog->node;
  
  printf (_("Onling %s help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
  {
    fputs (_("Please report translation bugs to "
            "<https://translationproject.org/team/>\n"), stdout);
  }
  
  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("The full documentations at <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("Alternately available locally through: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}
