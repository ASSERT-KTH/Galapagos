#ifndef C_H
#define C_H

#include <llvm/ADT/StringRef.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Module.h>
#include "llvm/IR/Constants.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/IRBuilder.h"
#include <llvm/IR/Instructions.h>
#include <cstdio>
#include <string>
#include <vector>


using namespace llvm;

namespace c {
    llvm::Function* cloneFunction(llvm::Function& function, llvm::Function& copyfrom);
    llvm::Function* synthNVersion(llvm::Function& original, std::vector<llvm::Function*>& variants);
}

#endif
