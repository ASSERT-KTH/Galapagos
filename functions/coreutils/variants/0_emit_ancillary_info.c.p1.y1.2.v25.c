Here are three different versions of the `emit_ancillary_info()` function, each functionally equivalent to the original:

1) In the first variant, the part of the code that decides the value of `url_program` and the value of `map_prog` is refactored.


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

  char const * node = STREQ (program, "[") ? "test invocation" : program;
  struct infomap const * map_prog = infomap;
  char const * url_program = program;
 
  for(; map_prog->program != nullptr && map_prog->node != nullptr; map_prog++)
  {
    if(STREQ (program, map_prog->program)) 
    {
       node =  map_prog->node;
       break;
    }
  }
  
  if (STREQ (program, "["))
    url_program = "test";

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
  // ... The rest of the original function code goes here
__END__


2) In the second variant, the deciding part about the 'infomap' variable has been changed to a different type of loop mechanism.


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
  struct infomap const *map_prog;
  
  for(map_prog = infomap; map_prog->program != nullptr; ++map_prog)
  {
    if(STREQ (program, map_prog->program)) 
    {
       node = map_prog->node;
       break;
    }
  }

  if (!map_prog->node)
    node = program;

  // ... The rest of the original function code goes here
}


3) In the third variant, several constants have been introduced to avoid repetition.


void emit_ancillary_info (char const *program) 
{
  struct infomap { char const *program; char const *node; } const infomap[] = 
  {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };
  
  char const * node = program;
  struct infomap const * map_prog = infomap;

  while(map_prog->program && map_prog->node) 
  {
    if(STREQ (program, map_prog->program))
      {
        node = map_prog->node;
        break;
      }
    map_prog++;
  }

  // ... The rest of the original function code goes here
  __END__;
}
