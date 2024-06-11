; ModuleID = '/home/javier/Galapagos/functions/libgcrypt/variants/c/0_barrett_reduce_3.bc'
source_filename = "/home/javier/Galapagos/functions/libgcrypt/variants/c/0_barrett_reduce_3.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local signext i16 @barrett_reduce(i16 noundef signext %a) #0 {
entry:
  %a.addr = alloca i16, align 2
  %v = alloca i16, align 2
  %t = alloca i32, align 4
  store i16 %a, ptr %a.addr, align 2
  store i16 12482, ptr %v, align 2
  %0 = load i16, ptr %a.addr, align 2
  %conv = sext i16 %0 to i32
  %mul = mul nsw i32 12482, %conv
  %add = add nsw i32 %mul, 33554432
  %shr = ashr i32 %add, 26
  store i32 %shr, ptr %t, align 4
  %1 = load i32, ptr %t, align 4
  %mul1 = mul nsw i32 %1, 3329
  store i32 %mul1, ptr %t, align 4
  %2 = load i16, ptr %a.addr, align 2
  %conv2 = sext i16 %2 to i32
  %3 = load i32, ptr %t, align 4
  %conv3 = trunc i32 %3 to i16
  %conv4 = sext i16 %conv3 to i32
  %sub = sub nsw i32 %conv2, %conv4
  %conv5 = trunc i32 %sub to i16
  ret i16 %conv5
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call signext i16 @barrett_reduce(i16 noundef signext 0)
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
