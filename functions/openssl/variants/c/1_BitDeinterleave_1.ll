; ModuleID = '/home/javier/Galapagos/functions/openssl/variants/c/1_BitDeinterleave_1.bc'
source_filename = "/home/javier/Galapagos/functions/openssl/variants/c/1_BitDeinterleave_1.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i64 @BitDeinterleave(i64 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @BitDeinterleave(i64 noundef %Ai) #0 {
entry:
  %Ai.addr = alloca i64, align 8
  %even = alloca i32, align 4
  %odd = alloca i32, align 4
  store i64 %Ai, ptr %Ai.addr, align 8
  %0 = load i64, ptr %Ai.addr, align 8
  %and = and i64 %0, 1431655765
  %conv = trunc i64 %and to i32
  store i32 %conv, ptr %even, align 4
  %1 = load i64, ptr %Ai.addr, align 8
  %shr = lshr i64 %1, 1
  %and1 = and i64 %shr, 1431655765
  %conv2 = trunc i64 %and1 to i32
  store i32 %conv2, ptr %odd, align 4
  %2 = load i32, ptr %even, align 4
  %shr3 = lshr i32 %2, 1
  %3 = load i32, ptr %even, align 4
  %or = or i32 %3, %shr3
  store i32 %or, ptr %even, align 4
  %4 = load i32, ptr %even, align 4
  %and4 = and i32 %4, 858993459
  store i32 %and4, ptr %even, align 4
  %5 = load i32, ptr %even, align 4
  %shr5 = lshr i32 %5, 2
  %6 = load i32, ptr %even, align 4
  %or6 = or i32 %6, %shr5
  store i32 %or6, ptr %even, align 4
  %7 = load i32, ptr %even, align 4
  %and7 = and i32 %7, 252645135
  store i32 %and7, ptr %even, align 4
  %8 = load i32, ptr %even, align 4
  %shr8 = lshr i32 %8, 4
  %9 = load i32, ptr %even, align 4
  %or9 = or i32 %9, %shr8
  store i32 %or9, ptr %even, align 4
  %10 = load i32, ptr %even, align 4
  %and10 = and i32 %10, 16711935
  store i32 %and10, ptr %even, align 4
  %11 = load i32, ptr %even, align 4
  %shr11 = lshr i32 %11, 8
  %12 = load i32, ptr %even, align 4
  %or12 = or i32 %12, %shr11
  store i32 %or12, ptr %even, align 4
  %13 = load i32, ptr %even, align 4
  %and13 = and i32 %13, 65535
  store i32 %and13, ptr %even, align 4
  %14 = load i32, ptr %odd, align 4
  %shr14 = lshr i32 %14, 1
  %15 = load i32, ptr %odd, align 4
  %or15 = or i32 %15, %shr14
  store i32 %or15, ptr %odd, align 4
  %16 = load i32, ptr %odd, align 4
  %and16 = and i32 %16, 858993459
  store i32 %and16, ptr %odd, align 4
  %17 = load i32, ptr %odd, align 4
  %shr17 = lshr i32 %17, 2
  %18 = load i32, ptr %odd, align 4
  %or18 = or i32 %18, %shr17
  store i32 %or18, ptr %odd, align 4
  %19 = load i32, ptr %odd, align 4
  %and19 = and i32 %19, 252645135
  store i32 %and19, ptr %odd, align 4
  %20 = load i32, ptr %odd, align 4
  %shr20 = lshr i32 %20, 4
  %21 = load i32, ptr %odd, align 4
  %or21 = or i32 %21, %shr20
  store i32 %or21, ptr %odd, align 4
  %22 = load i32, ptr %odd, align 4
  %and22 = and i32 %22, 16711935
  store i32 %and22, ptr %odd, align 4
  %23 = load i32, ptr %odd, align 4
  %shr23 = lshr i32 %23, 8
  %24 = load i32, ptr %odd, align 4
  %or24 = or i32 %24, %shr23
  store i32 %or24, ptr %odd, align 4
  %25 = load i32, ptr %odd, align 4
  %and25 = and i32 %25, 65535
  store i32 %and25, ptr %odd, align 4
  %26 = load i32, ptr %odd, align 4
  %conv26 = zext i32 %26 to i64
  %shl = shl i64 %conv26, 32
  %27 = load i32, ptr %even, align 4
  %conv27 = zext i32 %27 to i64
  %or28 = or i64 %shl, %conv27
  ret i64 %or28
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
