The changes made in the code given below are:

1. Instead of using a Struct to store the program names and node, a 2D array is used - infomap[][]. 
2. A for loop is used to loop over the array until a null value program or the matching program is found.
3. If the map's node is not null then the node variable referred by 'i' is stored.

This version of the function maintains the original functionality commented in bi-lingual comments.


void emit_ancillary_info (char const *program)
{
  char const *infomap[][2] =  {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  int i;

  /* through program-map while program rule isn't null and they aren't equivalent -> select next mapping */
  for(i = 0; infomap[i][0] && !STREQ (program, infomap[i][0]); i++);

  if (infomap[i][1])
    node = infomap[i][1];
  
  /* add post-processing formats in lines translated for bi-language compatibility */
  /* when the formatted message for foreign languages doubles as locale-response */
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    fputs (_("Report any translation bugs to "
             "<https://translationproject.org/team/>\n"), stdout);

  /* .htaccess on the coreutils web site maps programs to the appropriate page */
  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}

Note: This function contains a few exact string comparisons, please clarify domain and format specification for safer development!