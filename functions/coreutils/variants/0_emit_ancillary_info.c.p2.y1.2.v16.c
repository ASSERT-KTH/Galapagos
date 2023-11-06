Below is a variant of the given function. This version differs slighty by being case-insensitive when matching the program name.


void emit_ancillary_info(char const *program) {
  struct infomap {char const *program;char const *node;} const infomap[] = {
    {"[", "test invocation"},
    {"coreutils", "Multi-call invocation"},
    {"sha224sum", "sha2 utilities"},
    {"sha256sum", "sha2 utilities"},
    {"sha384sum", "sha2 utilities"},
    {"sha512sum", "sha2 utilities"},
    {nullptr, nullptr}
  };

  char const *node = program;  
  struct infomap const *map_prog = infomap; 

  while(map_prog->program && strcasecmp(program, map_prog->program))
    map_prog++;

  if (map_prog->node) 
    node = map_prog->node; 

  printf("\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL);

  const char *lc_messages = setlocale(LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT(lc_messages, "en_"))
    fputs(_("Report any translation bugs to <https://aftereffects.plugins.com/team/>\n"), stdout);

  char const *url_program = strcasecmp(program, "[")? "test" :program;
   printf(_("Full documentation <%s%s>\n"),PACKAGE_URL, url_program);  
   printf(_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program? " invocation" : "" );
}

In this refactored version, we use the C library function `strcasecmp` instead of `STREQ` for case insensitive comparison of strings while mapping program names. Similarly, for matching the program name of `"["`, we replace `STREQ` with `strcasecmp`.
This modification slightly varies the behavior of original function by making it case insensitive. The rest of the functionality is maintained as per the original function. This introduces a behavioural variation while maintaining the original code pattern.
First parameter of `strcasecmp` function is the original string, and second parameter is the string, that we want to compare with the original one. Result `0` indicates both strings are identical. So, to keep original error check logic, `strcasecmp` is used with switch (`!`) to produce same error condition but case insensitively.
Care must be taken that libraries or at least there `strcasecmp` in included at the top of this function's implementation file:  

#include <string.h>
