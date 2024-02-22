#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/IRBuilder.h"
#include <c/c.h>

extern unsigned DebugLevel;
namespace c {
  llvm::Function* cloneFunction(llvm::Function& function, llvm::Function& copyfrom) {


    FunctionType *FTy = function.getFunctionType();
    std::vector<Type *> Params(FTy->param_begin(), FTy->param_end());
    FunctionType *NFTy = FunctionType::get(FTy->getReturnType(), Params, false);
    unsigned NumArgs = Params.size();

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
  llvm::Function* synthNVersion(llvm::Function& function1, llvm::Function& function2) {
    function1.setName("version_1");
    
    FunctionType *FT2y = function2.getFunctionType();
    std::vector<Type *> Params2(FT2y->param_begin(), FT2y->param_end());
    FunctionType *NF2Ty = FunctionType::get(FT2y->getReturnType(), Params2, false);
    Function *NF2 = Function::Create(NF2Ty, function2.getLinkage(), function2.getAddressSpace());
    NF2->copyAttributesFrom(&function2);
    NF2->setComdat(function2.getComdat());
    NF2->setName("version_2");
    function1.getParent()->getFunctionList().insert(function1.getIterator(), NF2);

    NF2->splice(NF2->begin(), &function2);

    FunctionType *FTy = function1.getFunctionType();
    std::vector<Type *> Params(FTy->param_begin(), FTy->param_end());
    FunctionType *NFTy = FunctionType::get(FTy->getReturnType(), Params, false);
    unsigned NumArgs = Params.size();
    
    // Create the new function body and insert it into the module...
    Function *NF = Function::Create(NFTy, function1.getLinkage(), function1.getAddressSpace());
    NF->copyAttributesFrom(&function1);
    NF->setComdat(function1.getComdat());
    function1.getParent()->getFunctionList().insert(NF2->getIterator(), NF);
    NF->setName("n_version_call");


    function1.replaceAllUsesWith(ConstantExpr::getBitCast(NF, function1.getType()));
    BasicBlock* entry = BasicBlock::Create(NF->getContext(), "entry", NF);
    
    IRBuilder<> builder(entry);

    std::vector<Value*> params;
    for (auto& arg : NF->args()) {
        params.push_back(&arg);
    }

    ArrayRef<Value*> addParams(params);
    
    Value* callRes1 = builder.CreateCall(&function1, addParams);
    Value* callRes2 = builder.CreateCall(NF2, addParams);
   
    Value* cmp = builder.CreateICmpEQ(callRes1, callRes2);

    BasicBlock* trueBlock = BasicBlock::Create(NF->getContext(), "true", NF);
    BasicBlock* falseBlock = BasicBlock::Create(NF->getContext(), "false", NF);

    builder.CreateCondBr(cmp, trueBlock, falseBlock);

    builder.SetInsertPoint(trueBlock);
    builder.CreateRet(callRes1);

    builder.SetInsertPoint(falseBlock);
    builder.CreateCall(Function::Create(FunctionType::get(builder.getVoidTy(), false),
                                        Function::ExternalLinkage, "llvm.trap", function1.getParent()));
    builder.CreateUnreachable();
    return NF;
  }
}
