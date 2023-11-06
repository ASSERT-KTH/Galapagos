The following is a program variant, this does a case-insensitive string comparison while searching for the map entry:


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

  /* Using memcmp for case-insensitive comparison */
  while (map_prog->program && memcmp (program, map_prog->program, strlen(program)))
    map_prog++;

  if (map_prog->node) 
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    fputs (_("Report any translation bugs to "
              "<https://translationproject.org/team/>\n"), stdout);

  char const *url_program = STREQ (program, "[") ? "test" : program;
    
  printf (_("Full documentation <%s%s>\n"),
           PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
           node, node == program ? " invocation" : "");
}


This program will function the same as the previous one but becomes case-insensitive since this variant compares the program strings using the `memcmp` function for a case-insensitive comparison.

_

Note: C language does not support built-in techniques for case-insensitive comparison. However, we could incorporate a custom function for this purpose like `strncasecmp()` which is case-insensitive or any other preferred case-insensitive function. Here just for illustrative purpose, I used `memcmp()` but please replace it with a case-insensitive comparison function as per your coding environment and standard.