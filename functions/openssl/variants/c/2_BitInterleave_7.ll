; ModuleID = '/home/javier/Galapagos/functions/openssl/variants/c/2_BitInterleave_7.bc'
source_filename = "/home/javier/Galapagos/functions/openssl/variants/c/2_BitInterleave_7.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i64 @BitInterleave(i64 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @BitInterleave(i64 noundef %Ai) #0 {
entry:
  %Ai.addr = alloca i64, align 8
  %odd = alloca i64, align 8
  %even = alloca i64, align 8
  store i64 %Ai, ptr %Ai.addr, align 8
  %0 = load i64, ptr %Ai.addr, align 8
  %and = and i64 %0, -6148914691236517206
  store i64 %and, ptr %odd, align 8
  %1 = load i64, ptr %Ai.addr, align 8
  %and1 = and i64 %1, 6148914691236517205
  store i64 %and1, ptr %even, align 8
  %2 = load i64, ptr %odd, align 8
  %shr = lshr i64 %2, 1
  %3 = load i64, ptr %odd, align 8
  %or = or i64 %3, %shr
  store i64 %or, ptr %odd, align 8
  %4 = load i64, ptr %even, align 8
  %shl = shl i64 %4, 1
  %5 = load i64, ptr %even, align 8
  %or2 = or i64 %5, %shl
  store i64 %or2, ptr %even, align 8
  %6 = load i64, ptr %odd, align 8
  %and3 = and i64 %6, 3689348814741910323
  store i64 %and3, ptr %odd, align 8
  %7 = load i64, ptr %even, align 8
  %and4 = and i64 %7, -3689348814741910324
  store i64 %and4, ptr %even, align 8
  %8 = load i64, ptr %odd, align 8
  %shr5 = lshr i64 %8, 2
  %9 = load i64, ptr %odd, align 8
  %or6 = or i64 %9, %shr5
  store i64 %or6, ptr %odd, align 8
  %10 = load i64, ptr %even, align 8
  %shl7 = shl i64 %10, 2
  %11 = load i64, ptr %even, align 8
  %or8 = or i64 %11, %shl7
  store i64 %or8, ptr %even, align 8
  %12 = load i64, ptr %odd, align 8
  %and9 = and i64 %12, 1085102592571150095
  store i64 %and9, ptr %odd, align 8
  %13 = load i64, ptr %even, align 8
  %and10 = and i64 %13, -1085102592571150096
  store i64 %and10, ptr %even, align 8
  %14 = load i64, ptr %odd, align 8
  %shr11 = lshr i64 %14, 4
  %15 = load i64, ptr %odd, align 8
  %or12 = or i64 %15, %shr11
  store i64 %or12, ptr %odd, align 8
  %16 = load i64, ptr %even, align 8
  %shl13 = shl i64 %16, 4
  %17 = load i64, ptr %even, align 8
  %or14 = or i64 %17, %shl13
  store i64 %or14, ptr %even, align 8
  %18 = load i64, ptr %odd, align 8
  %and15 = and i64 %18, 71777214294589695
  store i64 %and15, ptr %odd, align 8
  %19 = load i64, ptr %even, align 8
  %and16 = and i64 %19, -71777214294589696
  store i64 %and16, ptr %even, align 8
  %20 = load i64, ptr %odd, align 8
  %shr17 = lshr i64 %20, 8
  %21 = load i64, ptr %odd, align 8
  %or18 = or i64 %21, %shr17
  store i64 %or18, ptr %odd, align 8
  %22 = load i64, ptr %even, align 8
  %shl19 = shl i64 %22, 8
  %23 = load i64, ptr %even, align 8
  %or20 = or i64 %23, %shl19
  store i64 %or20, ptr %even, align 8
  %24 = load i64, ptr %odd, align 8
  %and21 = and i64 %24, 281470681808895
  store i64 %and21, ptr %odd, align 8
  %25 = load i64, ptr %even, align 8
  %and22 = and i64 %25, -281470681808896
  store i64 %and22, ptr %even, align 8
  %26 = load i64, ptr %odd, align 8
  %shr23 = lshr i64 %26, 16
  %27 = load i64, ptr %odd, align 8
  %or24 = or i64 %27, %shr23
  store i64 %or24, ptr %odd, align 8
  %28 = load i64, ptr %even, align 8
  %shl25 = shl i64 %28, 16
  %29 = load i64, ptr %even, align 8
  %or26 = or i64 %29, %shl25
  store i64 %or26, ptr %even, align 8
  %30 = load i64, ptr %odd, align 8
  %and27 = and i64 %30, 4294967295
  store i64 %and27, ptr %odd, align 8
  %31 = load i64, ptr %even, align 8
  %and28 = and i64 %31, -4294967296
  store i64 %and28, ptr %even, align 8
  %32 = load i64, ptr %odd, align 8
  %33 = load i64, ptr %even, align 8
  %or29 = or i64 %32, %33
  ret i64 %or29
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
