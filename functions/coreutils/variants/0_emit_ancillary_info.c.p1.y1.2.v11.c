Option 1: Maintain the use of the array `infomap` for mapping the software names to their nodes, but without using pointer arithmetic and loop:


void emit_ancillary_info (char const *program)
{
    struct infomap { char const *program; char const *node; } infomap_row[] = 
    {
        { "[", "test invocation" },
        { "coreutils", "Multi-call invocation" },
        { "sha224sum", "sha2 utilities" },
        { "sha256sum", "sha2 utilities" },
        { "sha384sum", "sha2 utilities" },
        { "sha512sum", "sha2 utilities" },
        { nullptr, nullptr }
    };
    struct infomap *map_prog = infomap_row;
    int i = 0;
    while ( map_prog[i].program && !STREQ (program, map_prog[i].program))
        i++;
    
    char const *node = (map_prog[i].node) ? map_prog[i].node : program;

   /* Rest of the code is same from here */


Option 2: Replace the array-based map `infomap` with a couple sets of if-else statements for improved readability:


void emit_ancillary_info (char const *program)
{
  char const *node = program;
  if (STREQ( program, "[" )) { node = "test invocation"; }
  else if (STREQ( program, "coreutils")) { node = "Multi-call invocation"; }
  else if (
      STREQ( program, "sha224sum") || 
      STREQ( program, "sha256sum") || 
      STREQ( program, "sha384sum") || 
      STREQ( program, "sha512sum") 
  ) { node = "sha2 utilities"; }

  /* Rest of the code is same from here */
