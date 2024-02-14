#ifndef C_H
#define C_H

#include <llvm/ADT/StringRef.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Module.h>
#include "llvm/IR/Constants.h"
//#include "llvm/Support/IRBuilder.h"

#include <llvm/IR/Instructions.h>

using namespace llvm;

namespace c {
    llvm::Function* cloneFunction(llvm::Function& function, llvm::Function& copyfrom);
}

#endif
