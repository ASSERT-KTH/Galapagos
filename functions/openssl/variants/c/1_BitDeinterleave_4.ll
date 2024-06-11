; ModuleID = '/home/javier/Galapagos/functions/openssl/variants/c/1_BitDeinterleave_4.bc'
source_filename = "/home/javier/Galapagos/functions/openssl/variants/c/1_BitDeinterleave_4.c"
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
  %x = alloca i32, align 4
  %y = alloca i32, align 4
  %z = alloca i32, align 4
  %w = alloca i32, align 4
  %i = alloca i32, align 4
  store i64 %Ai, ptr %Ai.addr, align 8
  %0 = load i64, ptr %Ai.addr, align 8
  %and = and i64 %0, 4294967295
  %conv = trunc i64 %and to i32
  store i32 %conv, ptr %x, align 4
  %1 = load i64, ptr %Ai.addr, align 8
  %shr = lshr i64 %1, 32
  %conv1 = trunc i64 %shr to i32
  store i32 %conv1, ptr %y, align 4
  store i32 0, ptr %z, align 4
  store i32 0, ptr %w, align 4
  store i32 0, ptr %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %2 = load i32, ptr %i, align 4
  %cmp = icmp slt i32 %2, 16
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %3 = load i32, ptr %x, align 4
  %4 = load i32, ptr %i, align 4
  %mul = mul nsw i32 2, %4
  %shl = shl i32 1, %mul
  %and3 = and i32 %3, %shl
  %5 = load i32, ptr %i, align 4
  %shr4 = lshr i32 %and3, %5
  %6 = load i32, ptr %z, align 4
  %or = or i32 %6, %shr4
  store i32 %or, ptr %z, align 4
  %7 = load i32, ptr %y, align 4
  %8 = load i32, ptr %i, align 4
  %mul5 = mul nsw i32 2, %8
  %shl6 = shl i32 1, %mul5
  %and7 = and i32 %7, %shl6
  %9 = load i32, ptr %i, align 4
  %sub = sub nsw i32 %9, 16
  %shr8 = lshr i32 %and7, %sub
  %10 = load i32, ptr %z, align 4
  %or9 = or i32 %10, %shr8
  store i32 %or9, ptr %z, align 4
  %11 = load i32, ptr %x, align 4
  %12 = load i32, ptr %i, align 4
  %mul10 = mul nsw i32 2, %12
  %add = add nsw i32 %mul10, 1
  %shl11 = shl i32 1, %add
  %and12 = and i32 %11, %shl11
  %13 = load i32, ptr %i, align 4
  %add13 = add nsw i32 %13, 1
  %shr14 = lshr i32 %and12, %add13
  %14 = load i32, ptr %w, align 4
  %or15 = or i32 %14, %shr14
  store i32 %or15, ptr %w, align 4
  %15 = load i32, ptr %y, align 4
  %16 = load i32, ptr %i, align 4
  %mul16 = mul nsw i32 2, %16
  %add17 = add nsw i32 %mul16, 1
  %shl18 = shl i32 1, %add17
  %and19 = and i32 %15, %shl18
  %17 = load i32, ptr %i, align 4
  %sub20 = sub nsw i32 %17, 15
  %shr21 = lshr i32 %and19, %sub20
  %18 = load i32, ptr %w, align 4
  %or22 = or i32 %18, %shr21
  store i32 %or22, ptr %w, align 4
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %19 = load i32, ptr %i, align 4
  %inc = add nsw i32 %19, 1
  store i32 %inc, ptr %i, align 4
  br label %for.cond, !llvm.loop !6

for.end:                                          ; preds = %for.cond
  %20 = load i32, ptr %w, align 4
  %conv23 = zext i32 %20 to i64
  %shl24 = shl i64 %conv23, 32
  %21 = load i32, ptr %z, align 4
  %conv25 = zext i32 %21 to i64
  %or26 = or i64 %shl24, %conv25
  ret i64 %or26
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
