; ModuleID = '/home/javier/Galapagos/functions/libgcrypt/variants/c/0_barrett_reduce_2.bc'
source_filename = "/home/javier/Galapagos/functions/libgcrypt/variants/c/0_barrett_reduce_2.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local signext i16 @barrett_reduce(i16 noundef signext %a) #0 {
entry:
  %a.addr = alloca i16, align 2
  %t = alloca i16, align 2
  %v = alloca i16, align 2
  store i16 %a, ptr %a.addr, align 2
  store i16 12482, ptr %v, align 2
  %0 = load i16, ptr %a.addr, align 2
  %conv = sext i16 %0 to i64
  %mul = mul nsw i64 12482, %conv
  %add = add nsw i64 %mul, 33554432
  %shr = ashr i64 %add, 26
  %conv1 = trunc i64 %shr to i16
  store i16 %conv1, ptr %t, align 2
  %1 = load i16, ptr %t, align 2
  %conv2 = sext i16 %1 to i32
  %mul3 = mul nsw i32 3329, %conv2
  %conv4 = trunc i32 %mul3 to i16
  store i16 %conv4, ptr %t, align 2
  %2 = load i16, ptr %a.addr, align 2
  %conv5 = sext i16 %2 to i32
  %3 = load i16, ptr %t, align 2
  %conv6 = sext i16 %3 to i32
  %sub = sub nsw i32 %conv5, %conv6
  %conv7 = trunc i32 %sub to i16
  ret i16 %conv7
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
