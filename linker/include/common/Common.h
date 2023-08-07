#ifndef COMMON_H
#define COMMON_H

#include <llvm/ADT/StringRef.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Module.h>
#include "llvm/IR/Constants.h"
//#include "llvm/Support/IRBuilder.h"

using namespace llvm;

namespace common {
  llvm::Function* getFunctionByName(llvm::Module& mod, llvm::StringRef name);
  llvm::Function* cloneFunction(llvm::Module& inmodule, llvm::Function& function, llvm::Function& copyfrom);
}

#endif
