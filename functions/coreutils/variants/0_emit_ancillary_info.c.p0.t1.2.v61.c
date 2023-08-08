emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "sha1sum", "SHA-1 utilities" }, // Added sha1sum with new node 'SHA-1 utilities'
    { "md5sum", "MD5 utilities" }, // Added md5sum with new node 'MD5 utilities'
    { "[",  "test invocation" },
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

  printf (_("\n%s software help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL); // Changed 'online' to 'software'.

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "fr_")) // Changed locale from 'en_;' to 'fr_'.
    {
      fputs (_("Report translation errors to "  // Changed 'bugs' to 'errors'
              "<https://translationproject.org/team/>\n"), stdout);
    }
  
  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation is found at<%s%s>\n"), // Added ' is found at' 
          PACKAGE_URL, url_program);
  printf (_("Alternatively, local documents are: info '(coreutils) %s%s'\n"), // Changed text to 'Alternatively, local documents are: '  
          node, node == program ? " invocation" : "");
}

The modifications to the original function include new program entries, slight changes to the message wording, a change to the LOCALE in the 'lc_message' evaluation (causing a new translation website message string to be reinterpreted and changing the language setting), and additions to the strings for 'url_Program' and 'node'.
All alterations maintain the function's original purpose: to provide informative web links to online resources based on the parameter, otherwise referred by the argument 'program'.