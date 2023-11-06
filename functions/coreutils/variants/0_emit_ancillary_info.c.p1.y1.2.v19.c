Variant 1: Using the for loop instead of while loop

emit_ancillary_info (char const *program)
{
  struct infomap 
  {
    char const* program; 
    char const* node; 
  } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const* node = program;

  struct infomap const* map_prog = infomap;
  for (;map_prog->program && ! STREQ (program, map_prog->program); map_prog++);

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  char const* lc_messages = setlocale (LC_MESSAGES, nullptr);
  
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_")) 
  {
    fputs (_("Report any translation bugs to "
             "<https://translationproject.org/team/>\n"), stdout);
  }

  char const* url_program = STREQ (program, "[") ? "test" : program;
  
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}


 Variant 2: Early Return 

emit_ancillary_info (char const *program)
{
  struct infomap 
  {
    char const* program; 
    char const* node; 
  } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const* node = program;
  struct infomap const* map_prog = infomap;
  
  while (map_prog->program) 
  {
    if (STREQ (program, map_prog->program)) 
    {
      node = map_prog->node;
      break;
    }
    map_prog++;
  } 

  if(node == nullptr)
    return;
	
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
  char const* lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
  {
    fputs (_("Report any translation bugs to "
             "<https://translationproject.org/team/>\n"), stdout);
  }

  char const* url_program = STREQ (program, "[") ? "test" : program;

  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}


Variant 3: Using do-while instead of while loop

emit_ancillary_info (char const *program)
{
  struct infomap 
  {
    char const* program; 
    char const* node; 
  } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const* node = program;
  struct infomap const* map_prog = infomap;
  
  do 
  {
    if(!map_prog->program) 
      break;
	
    if(STREQ (program, map_prog->program))
    {
      node = map_prog->node;
      break;
    }

    map_prog++;
  } 
  while (true);
  
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  char const* lc_messages = setlocale (LC_MESSAGES, nullptr);
  
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
  {
    fputs (_("Report translation bugs to "
             "<https://translationproject.org/team/>\n"), stdout);
  }
  char const* url_program = STREQ (program, "[") ? "test" : program;

  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);

  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}
