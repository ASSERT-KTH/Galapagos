# llm-envy

## Requirements

### Verifier module
- Uses alive2 with the translation validation tool. Steps for building here, https://github.com/AliveToolkit/alive2 
    - Requirements for alive2 are needed: cmake, gcc/clang, re2c, Z3 

## NOTES 13-04-2023
- The prompt needs the specification about writing only code. This is sanitization in the end.
- With O3, we reach 60% of preservation in machine code. We start to repeat the same source code after the generation number 50.
- The prompt affects the diversification. Second experiment with a different prompt shows that even in the second iteration it generates the same source code. The preservation reaches a 30% the first one, reaches 60%. The main difference are the keywords "different but equivalent".
