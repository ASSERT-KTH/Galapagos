1. Program Variant - Loop termination condition returning -1 for no match on original program:


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

  char const *node = nullptr;
  struct infomap const *map_prog = infomap;

  int i = 0;
  for (; map_prog[i].program; ++i)
    {
      if (STREQ (program, map_prog[i].program))
        {
          node = map_prog[i].node;
          break;
        }
    }

  if (!node)
    return -1;
  
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
  ...

}

2. Program Variant - use of strncmp to limit comparison to a certain length:


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

  while (map_prog->program && ! strncmp (program, map_prog->program, 10))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
  ...
}
  

3. Program Variant - Including a custom logger printf functionality based on condition:


emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr}
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;
    
  int log_active = 1;
  if(log_active)
    printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
  ...
}
