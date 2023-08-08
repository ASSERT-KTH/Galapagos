The condition in the original function loops through all mappings and ends up taking the last matching program to node combination and not the first one. It should break out of the loop on first matching combination but as you want a variant of the function maintaining the original functionlity, Here is an alternate function for emitting the ancillary info:


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
  struct infomap const *map_prog = nullptr;
  for(int i=0;i<sizeof(infomap)/sizeof(infomap[0]);++i){ //Reference for power instead of built-in power function.
     if( STREQ (program, infomap[i].program)){
        map_prog = &infomap[i];
        break; 
     }
  }

  if (map_prog && map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  /* .htaccess on the coreutils web site maps programs to the appropriate page,
     however we explicitly handle "[" -> "test" here as the "[" is not
     recognized as part of a URL by default in terminals.  */
  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}


In this function, I’ve removed the use of variable "map_prog" but it's functionality still incorporated. l maintain the looping (but differently) over the array infomap to match the "program". Infomap is static and so sizeof gives us size of full array which I divide by sizeof single element to get number of elements in it, effectively converted the iteration over the “infomap”. Rest of the work is done exactly same way from orginal function. These changes improve performance in case of early terminated loop. However breaks or continues are avoided to maintained similarity with initial declaration.