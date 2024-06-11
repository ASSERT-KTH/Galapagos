; ModuleID = '/home/javier/Galapagos/functions/openssl/variants/c/2_BitInterleave_4.bc'
source_filename = "/home/javier/Galapagos/functions/openssl/variants/c/2_BitInterleave_4.c"
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
  %result = alloca i64, align 8
  %mask1 = alloca i64, align 8
  %i = alloca i32, align 4
  store i64 %Ai, ptr %Ai.addr, align 8
  store i64 0, ptr %result, align 8
  store i64 6148914691236517205, ptr %mask1, align 8
  %0 = load i64, ptr %Ai.addr, align 8
  %1 = load i64, ptr %Ai.addr, align 8
  %shl = shl i64 %1, 16
  %or = or i64 %0, %shl
  %and = and i64 %or, 281470681808895
  store i64 %and, ptr %Ai.addr, align 8
  %2 = load i64, ptr %Ai.addr, align 8
  %3 = load i64, ptr %Ai.addr, align 8
  %shl1 = shl i64 %3, 8
  %or2 = or i64 %2, %shl1
  %and3 = and i64 %or2, 71777214294589695
  store i64 %and3, ptr %Ai.addr, align 8
  %4 = load i64, ptr %Ai.addr, align 8
  %5 = load i64, ptr %Ai.addr, align 8
  %shl4 = shl i64 %5, 4
  %or5 = or i64 %4, %shl4
  %and6 = and i64 %or5, 1085102592571150095
  store i64 %and6, ptr %Ai.addr, align 8
  %6 = load i64, ptr %Ai.addr, align 8
  %7 = load i64, ptr %Ai.addr, align 8
  %shl7 = shl i64 %7, 2
  %or8 = or i64 %6, %shl7
  %and9 = and i64 %or8, 3689348814741910323
  store i64 %and9, ptr %Ai.addr, align 8
  %8 = load i64, ptr %Ai.addr, align 8
  %9 = load i64, ptr %Ai.addr, align 8
  %shl10 = shl i64 %9, 1
  %or11 = or i64 %8, %shl10
  %and12 = and i64 %or11, 6148914691236517205
  store i64 %and12, ptr %Ai.addr, align 8
  store i32 0, ptr %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %10 = load i32, ptr %i, align 4
  %cmp = icmp slt i32 %10, 64
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %11 = load i64, ptr %Ai.addr, align 8
  %12 = load i64, ptr %mask1, align 8
  %and13 = and i64 %11, %12
  %13 = load i32, ptr %i, align 4
  %sh_prom = zext i32 %13 to i64
  %shl14 = shl i64 %and13, %sh_prom
  %14 = load i64, ptr %result, align 8
  %or15 = or i64 %14, %shl14
  store i64 %or15, ptr %result, align 8
  %15 = load i64, ptr %Ai.addr, align 8
  %shr = lshr i64 %15, 1
  %16 = load i64, ptr %mask1, align 8
  %and16 = and i64 %shr, %16
  %17 = load i32, ptr %i, align 4
  %add = add nsw i32 %17, 1
  %sh_prom17 = zext i32 %add to i64
  %shl18 = shl i64 %and16, %sh_prom17
  %18 = load i64, ptr %result, align 8
  %or19 = or i64 %18, %shl18
  store i64 %or19, ptr %result, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %19 = load i32, ptr %i, align 4
  %add20 = add nsw i32 %19, 2
  store i32 %add20, ptr %i, align 4
  br label %for.cond, !llvm.loop !6

for.end:                                          ; preds = %for.cond
  %20 = load i64, ptr %result, align 8
  ret i64 %20
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
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
