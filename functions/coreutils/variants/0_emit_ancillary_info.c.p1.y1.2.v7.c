1. Code Variant by Reversing the Mapping:

The below variant is done by reversing the original infomap array and iterating using decrement instead of increment.


void emit_ancillary_info_1 (char const *program){
  struct infomap { char const *program; char const *node; } const infomap_reverse[] = {
    { nullptr, nullptr },
    { "sha512sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha224sum", "sha2 utilities" },
    { "coreutils", "Multi-call invocation" },
    { "[", "test invocation" },  
  };
  
  char const *node = program;
  size_t map_size = sizeof(infomap_reverse)/sizeof(infomap_reverse[0]);
  struct infomap const *map_prog = &infomap_reverse[map_size-1];

  while (!map_prog->program && map_prog->program != program)
    map_prog--;

  if (map_prog->node)
    node = map_prog->node;

  
  /* Rest of the original code as it is */
}



2. Code Variant by using For loop instead of While:

The following variant replaces while loop with a for loop traversal along the infomap[].


void emit_ancillary_info_2 (char const *program){
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

  for(int i=0;infomap[i].program!=nullptr;i++){
    if(!STREQ (program, infomap[i].program)){
      map_prog = &infomap[i];
      break;
    }
  }

  if (map_prog->node)
    node = map_prog->node;

  
  /* Rest of the original code as it is */  



