; ModuleID = '/home/javier/Galapagos/functions/libgcrypt/4_montgomery_reduce.once.bc'
source_filename = "/home/javier/Galapagos/functions/libgcrypt/4_montgomery_reduce.run.once.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local signext i16 @montgomery_reduce(i32 noundef %a) #0 {
entry:
  %sext = mul i32 %a, -218038272
  %sext.0 = ashr exact i32 %sext, 16
  %mul.1.neg = mul nsw i32 %sext.0, -3329
  %sub.0 = add i32 %mul.1.neg, %a
  %0 = lshr i32 %sub.0, 16
  %trunc.2 = trunc i32 %0 to i16
  ret i16 %trunc.2
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call signext i16 @montgomery_reduce(i32 noundef 0)
  ret i32 0
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 17.0.0 (git@github.com:llvm/llvm-project.git 1a7a00bdc99fa2b2ca19ecd2d1069991b3c1006b)"}
