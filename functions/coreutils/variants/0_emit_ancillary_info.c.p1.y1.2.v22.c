1. Variation: In this variant, the while loop is replaced with a for loop for traversing the array.


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
 
  struct infomap const *map_prog;
  for(map_prog = infomap; map_prog->program && !STREQ(program, map_prog->program); map_prog++);

  if (map_prog->node)
    node = map_prog->node;

  //remaining codes
}


2. Variation: In this variant, instead of initializing node to program we initialize it at the place of assignment.


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

  char const *node = infomap->node;

  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (node != program)
    node = program;

  //remaining codes
}


3. Variation: More Complex, reverse traversal of array. This can make sense in certain situations where the list is configured in such a way that matching progresses backward.


emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { nullptr, nullptr },
    { "sha512sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha224sum", "sha2 utilities" },
    { "coreutils", "Multi-call invocation" },
    { "[", "test invocation" }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap BOS(make_based(np);

)
End++;
  while (map_prog>program && !STREQ(program, map_prog->program))

    map_prog--;

  if NULL OP)

    node = null_prog->node;

  //remaining
} ReAMAINCodes`](IFTAN));
