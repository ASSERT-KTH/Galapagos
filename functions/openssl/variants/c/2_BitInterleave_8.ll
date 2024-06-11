; ModuleID = '/home/javier/Galapagos/functions/openssl/variants/c/2_BitInterleave_8.bc'
source_filename = "/home/javier/Galapagos/functions/openssl/variants/c/2_BitInterleave_8.c"
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
  %t0 = alloca i64, align 8
  %t1 = alloca i64, align 8
  store i64 %Ai, ptr %Ai.addr, align 8
  %0 = load i64, ptr %Ai.addr, align 8
  %and = and i64 %0, 4294967295
  store i64 %and, ptr %t0, align 8
  %1 = load i64, ptr %Ai.addr, align 8
  %shr = lshr i64 %1, 32
  store i64 %shr, ptr %t1, align 8
  %2 = load i64, ptr %t0, align 8
  %3 = load i64, ptr %t0, align 8
  %shl = shl i64 %3, 16
  %or = or i64 %2, %shl
  %and1 = and i64 %or, 281470681808895
  store i64 %and1, ptr %t0, align 8
  %4 = load i64, ptr %t0, align 8
  %5 = load i64, ptr %t0, align 8
  %shl2 = shl i64 %5, 8
  %or3 = or i64 %4, %shl2
  %and4 = and i64 %or3, 71777214294589695
  store i64 %and4, ptr %t0, align 8
  %6 = load i64, ptr %t0, align 8
  %7 = load i64, ptr %t0, align 8
  %shl5 = shl i64 %7, 4
  %or6 = or i64 %6, %shl5
  %and7 = and i64 %or6, 1085102592571150095
  store i64 %and7, ptr %t0, align 8
  %8 = load i64, ptr %t0, align 8
  %9 = load i64, ptr %t0, align 8
  %shl8 = shl i64 %9, 2
  %or9 = or i64 %8, %shl8
  %and10 = and i64 %or9, 3689348814741910323
  store i64 %and10, ptr %t0, align 8
  %10 = load i64, ptr %t0, align 8
  %11 = load i64, ptr %t0, align 8
  %shl11 = shl i64 %11, 1
  %or12 = or i64 %10, %shl11
  %and13 = and i64 %or12, 6148914691236517205
  store i64 %and13, ptr %t0, align 8
  %12 = load i64, ptr %t1, align 8
  %13 = load i64, ptr %t1, align 8
  %shl14 = shl i64 %13, 16
  %or15 = or i64 %12, %shl14
  %and16 = and i64 %or15, 281470681808895
  store i64 %and16, ptr %t1, align 8
  %14 = load i64, ptr %t1, align 8
  %15 = load i64, ptr %t1, align 8
  %shl17 = shl i64 %15, 8
  %or18 = or i64 %14, %shl17
  %and19 = and i64 %or18, 71777214294589695
  store i64 %and19, ptr %t1, align 8
  %16 = load i64, ptr %t1, align 8
  %17 = load i64, ptr %t1, align 8
  %shl20 = shl i64 %17, 4
  %or21 = or i64 %16, %shl20
  %and22 = and i64 %or21, 1085102592571150095
  store i64 %and22, ptr %t1, align 8
  %18 = load i64, ptr %t1, align 8
  %19 = load i64, ptr %t1, align 8
  %shl23 = shl i64 %19, 2
  %or24 = or i64 %18, %shl23
  %and25 = and i64 %or24, 3689348814741910323
  store i64 %and25, ptr %t1, align 8
  %20 = load i64, ptr %t1, align 8
  %21 = load i64, ptr %t1, align 8
  %shl26 = shl i64 %21, 1
  %or27 = or i64 %20, %shl26
  %and28 = and i64 %or27, 6148914691236517205
  store i64 %and28, ptr %t1, align 8
  %22 = load i64, ptr %t0, align 8
  %shl29 = shl i64 %22, 1
  %23 = load i64, ptr %t1, align 8
  %or30 = or i64 %shl29, %23
  ret i64 %or30
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
