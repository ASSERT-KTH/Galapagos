#include "common/Common.h"



extern unsigned DebugLevel;

namespace common {
  // Extract function by name
  // Receives the bitcode structure and the function name
  // Returns a pointer to the function extracted
  // Returns null if the function is not found
  //
  llvm::Function* getFunctionByName(llvm::Module& mod, llvm::StringRef name) {
     // Iterate over all functions of mod
     for(auto &F: mod) {
       if(DebugLevel > 2) {
          errs() << "\t" << F.getName() << "\n";
       }

       // Compare the names
       if(F.getName() == name && !F.isDeclaration()) {
          if(DebugLevel > 2) {
            errs() << "\tFunction found !\n";
          }
          if(DebugLevel > 3) {
            errs() << F << "\n";
          }
          return &F;
       }
     }

     // Return null ptr
     return NULL;
  }
}

