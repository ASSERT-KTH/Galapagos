Here are some code transformed variants that keep the function's behaviour intact.
The replacements include changing the diverse parts of the variables and code without mutating any structural or logical concepts within the work. For example, replacement of symbolic constants, changing condition perception, complement of conditions etc. The current set utitlizes recursion, pointer arithmetics, loop interchange, etc.

Example 1: Using recursion instead of while loop.


void emit_ancillary_info (char const *program)
{
  struct Infomap {
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
  struct Infomap const *map_program = infomap;
  	
  check_infomap(&map_program, program, &node);

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  
  if (!(!lc_messages || !STRNCMP_LIT (lc_messages, "en_"))) {
    fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
}

  char const *url_program = STREQ (program, "[") 

  printf (_("Full documentation <%s%s>\n"),            
          !STREQ(program, STREQ (program, "[")) ? url_program : "test");

    printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}

void check_infomap(infomap **map_prog, char const *program, char const **node ) {

    if( !( *map_prog->program && ! STREQ (program, (*map_prog)->program) ) {
		
	    if ((*map_prog)->node)
                return *node = (*map_prog->node ;
          check_infomap(++(*map_prog), program, node );
     }
     else {
            return;
     }
}



Removing Redundant Message Condition in Example 2:


emit_ancillary_info_v2 (char const *program)
{
  struct infomap_v2 { char const *program_v2;
                    char const *node_v2; } const infomap_v2[] = 
   {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
  };

  char const *node_v2 = program;
  struct infomap_v2 const *map_prog_v2 = infomap_v2;

  while (map_prog_v2->program_v2 && ! STREQ (program, map_prog_v2->program_v2))
    map_prog_v2++;

  if (map_prog_v2->node_v2)
    node_v2 = map_prog_v2->node_v2;

  printf (_("\n%s online help (English): <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  fputs (_("Report any translation bugs to "
           "<https://translationproject.org/team/>\n"), stdout);

  char const *url_program_v2 = STREQ (program, "[") ? "test" : program;
  
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program_v2);
  
  printf (_("or available locally via: info '(coreutils) %s-%s'\n"),
          node_v2, STREQ (node_v2, program) ? "-invocation" : "");
}
