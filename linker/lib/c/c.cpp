#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/IRBuilder.h"
#include <c/c.h>
#include <cstdio>
#include <string>
#include <vector>

extern unsigned DebugLevel;
namespace c {
  llvm::Function* cloneFunction(llvm::Function& function, llvm::Function& copyfrom) {

    FunctionType *FTy = function.getFunctionType();
    std::vector<Type *> Params(FTy->param_begin(), FTy->param_end());
    FunctionType *NFTy = FunctionType::get(FTy->getReturnType(), Params, false);

    // Create the new function body and insert it into the module...
    Function *NF = Function::Create(NFTy, function.getLinkage(), function.getAddressSpace());
    NF->copyAttributesFrom(&function);
    NF->setComdat(function.getComdat());
    function.getParent()->getFunctionList().insert(function.getIterator(), NF);
    NF->takeName(&function);


    NF->splice(NF->begin(), &copyfrom);

    auto I = copyfrom.arg_begin();
    auto I2 = NF->arg_begin();

    // Setting the name of the arguments
   for (Function::arg_iterator E = copyfrom.arg_end();
       I != E; ++I, ++I2) {
       errs() << *I2 << "\n";
       errs() << *I << "\n";
       // Move the name and users over to the new version.
       I2->takeName(&*I);
       I->replaceAllUsesWith(&*I2);

   }
    // Replace calls by this one

    // TODO replace also the calls to NF by NF itself

    // Fix up any BlockAddresses that refer to the function.
    function.replaceAllUsesWith(ConstantExpr::getBitCast(NF, function.getType()));
    // Finally, nuke the old function.
    function.eraseFromParent();


    if(DebugLevel > 2){
      errs() << "New function \n";
      errs() <<  *NF << "\n";
    }
    return NF;
  }


  llvm::Function* synthNVersion(llvm::Function& original, std::vector<llvm::Function*>& variants) {
    original.setName("version_1");
    
    FunctionType *FTy = original.getFunctionType();
    std::vector<Type *> Params(FTy->param_begin(), FTy->param_end());
    FunctionType *NFTy = FunctionType::get(FTy->getReturnType(), Params, false);
    // Create the new function body and insert it into the module...
    Function *NF = Function::Create(NFTy, original.getLinkage(), original.getAddressSpace());
    NF->copyAttributesFrom(&original);
    NF->setComdat(original.getComdat());
    NF->setName("n_version_call");
    
    original.getParent()->getFunctionList().insert(original.getIterator(), NF);
    original.replaceAllUsesWith(ConstantExpr::getBitCast(NF, original.getType()));
    BasicBlock* entry = BasicBlock::Create(NF->getContext(), "entry", NF);
    
    IRBuilder<> builder(entry);

    std::vector<Value*> params;
    for (auto& arg : NF->args()) {
        params.push_back(&arg);
    }

    ArrayRef<Value*> addParams(params);
    
    Value* callRes1 = builder.CreateCall(&original, addParams);
   
    std::vector<Value*> calls;

    int n = 2;
    for (auto it = variants.begin(); it != variants.end(); it++){
        auto function2 = *it;
        FunctionType *FT2y = function2->getFunctionType();
        std::vector<Type *> Params2(FT2y->param_begin(), FT2y->param_end());
        FunctionType *NF2Ty = FunctionType::get(FT2y->getReturnType(), Params2, false);
        Function *NF2 = Function::Create(NF2Ty, function2->getLinkage(), function2->getAddressSpace());
        NF2->copyAttributesFrom(function2);
        NF2->setComdat(function2->getComdat());

        std::string fn_name("version_");
        fn_name.append(std::to_string(n));
        NF2->setName(fn_name);
        
        NF->getParent()->getFunctionList().insert(original.getIterator(), NF2);
        NF2->splice(NF2->begin(), function2);
        calls.push_back(builder.CreateCall(NF2, addParams));
        n++;
    }

    BasicBlock* comparisons = BasicBlock::Create(NF->getContext(), "comparisons", NF);
    builder.CreateBr(comparisons);

    BasicBlock* falseBlock = BasicBlock::Create(NF->getContext(), "error", NF);
    builder.SetInsertPoint(falseBlock);
    builder.CreateCall(Function::Create(FunctionType::get(builder.getVoidTy(), false),
                Function::ExternalLinkage, "llvm.trap", original.getParent()));
    builder.CreateUnreachable();

    
    builder.SetInsertPoint(comparisons);
    for (std::size_t i = 0; i < calls.size(); i++){
        Value* cmp = builder.CreateICmpEQ(callRes1, calls[i]);
        BasicBlock* trueBlock = BasicBlock::Create(NF->getContext(), "true", NF, falseBlock);

        builder.CreateCondBr(cmp, trueBlock, falseBlock);

        builder.SetInsertPoint(trueBlock);
        if(i == calls.size() - 1) {
            builder.CreateRet(callRes1);
        }
    }

    return NF;
  }
}
