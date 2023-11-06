The code variant below retains all functionality of the original function in the question but adds functionality to show ancillary information through conditional statements. The variant checks for particular programs in the infomap and outputs an extra note regarding those in particular. 


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

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;
  
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
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);

  // separate message for sha2 utilities
  if (STREQ (program, "sha224sum") || STREQ (program, "sha256sum") || 
      STREQ (program, "sha384sum") || STREQ (program, "sha512sum")) 
  { 
    printf (_("Note: SHA-2 is a set of cryptographic hash functions "
              "(including SHA-224, SHA-256, SHA-384, SHA-512)\n"));
  }

  printf (_("Or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}

The change is as below:

Added an additional Conditional Statement to check whether the passed program argument belonged to SHA-2 denominators present in struct. If a user passes any of the tested denominators, now this program will also output a note regarding SHA-2!