; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/c/2_muldiv_down_4.bc'
source_filename = "/home/javier/Galapagos/functions/alsa-lib/variants/c/2_muldiv_down_4.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @muldiv_down(i32 noundef 0, i32 noundef 0, i32 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @muldiv_down(i32 noundef %a, i32 noundef %b, i32 noundef %c) #0 {
entry:
  %a.addr = alloca i32, align 4
  %b.addr = alloca i32, align 4
  %c.addr = alloca i32, align 4
  %v = alloca i64, align 8
  %result = alloca i32, align 4
  store i32 %a, ptr %a.addr, align 4
  store i32 %b, ptr %b.addr, align 4
  store i32 %c, ptr %c.addr, align 4
  %0 = load i32, ptr %a.addr, align 4
  %conv = sext i32 %0 to i64
  %1 = load i32, ptr %b.addr, align 4
  %conv1 = sext i32 %1 to i64
  %mul = mul nsw i64 %conv, %conv1
  store i64 %mul, ptr %v, align 8
  %2 = load i32, ptr %c.addr, align 4
  %conv2 = sext i32 %2 to i64
  %3 = load i64, ptr %v, align 8
  %div = sdiv i64 %3, %conv2
  store i64 %div, ptr %v, align 8
  %4 = load i64, ptr %v, align 8
  %cmp = icmp sgt i64 %4, 2147483647
  br i1 %cmp, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  br label %cond.end9

cond.false:                                       ; preds = %entry
  %5 = load i64, ptr %v, align 8
  %cmp4 = icmp slt i64 %5, -2147483648
  br i1 %cmp4, label %cond.true6, label %cond.false7

cond.true6:                                       ; preds = %cond.false
  br label %cond.end

cond.false7:                                      ; preds = %cond.false
  %6 = load i64, ptr %v, align 8
  %conv8 = trunc i64 %6 to i32
  br label %cond.end

cond.end:                                         ; preds = %cond.false7, %cond.true6
  %cond = phi i32 [ -2147483648, %cond.true6 ], [ %conv8, %cond.false7 ]
  br label %cond.end9

cond.end9:                                        ; preds = %cond.end, %cond.true
  %cond10 = phi i32 [ 2147483647, %cond.true ], [ %cond, %cond.end ]
  store i32 %cond10, ptr %result, align 4
  %7 = load i32, ptr %result, align 4
  ret i32 %7
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
