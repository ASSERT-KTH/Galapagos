; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/c/2_b64_char_to_byte_5.bc'
source_filename = "/home/javier/Galapagos/functions/libsodium/variants/c/2_b64_char_to_byte_5.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @b64_char_to_byte(i32 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @b64_char_to_byte(i32 noundef %c) #0 {
entry:
  %c.addr = alloca i32, align 4
  store i32 %c, ptr %c.addr, align 4
  %0 = load i32, ptr %c.addr, align 4
  %cmp = icmp sge i32 %0, 65
  br i1 %cmp, label %land.rhs, label %land.end

land.rhs:                                         ; preds = %entry
  %1 = load i32, ptr %c.addr, align 4
  %cmp1 = icmp sle i32 %1, 90
  br label %land.end

land.end:                                         ; preds = %land.rhs, %entry
  %2 = phi i1 [ false, %entry ], [ %cmp1, %land.rhs ]
  %land.ext = zext i1 %2 to i32
  %3 = load i32, ptr %c.addr, align 4
  %sub = sub nsw i32 %3, 65
  %mul = mul nsw i32 %land.ext, %sub
  %4 = load i32, ptr %c.addr, align 4
  %cmp2 = icmp sge i32 %4, 97
  br i1 %cmp2, label %land.rhs3, label %land.end5

land.rhs3:                                        ; preds = %land.end
  %5 = load i32, ptr %c.addr, align 4
  %cmp4 = icmp sle i32 %5, 122
  br label %land.end5

land.end5:                                        ; preds = %land.rhs3, %land.end
  %6 = phi i1 [ false, %land.end ], [ %cmp4, %land.rhs3 ]
  %land.ext6 = zext i1 %6 to i32
  %7 = load i32, ptr %c.addr, align 4
  %sub7 = sub nsw i32 %7, 97
  %add = add nsw i32 %sub7, 26
  %mul8 = mul nsw i32 %land.ext6, %add
  %add9 = add nsw i32 %mul, %mul8
  %8 = load i32, ptr %c.addr, align 4
  %cmp10 = icmp sge i32 %8, 48
  br i1 %cmp10, label %land.rhs11, label %land.end13

land.rhs11:                                       ; preds = %land.end5
  %9 = load i32, ptr %c.addr, align 4
  %cmp12 = icmp sle i32 %9, 57
  br label %land.end13

land.end13:                                       ; preds = %land.rhs11, %land.end5
  %10 = phi i1 [ false, %land.end5 ], [ %cmp12, %land.rhs11 ]
  %land.ext14 = zext i1 %10 to i32
  %11 = load i32, ptr %c.addr, align 4
  %sub15 = sub nsw i32 %11, 48
  %add16 = add nsw i32 %sub15, 52
  %mul17 = mul nsw i32 %land.ext14, %add16
  %add18 = add nsw i32 %add9, %mul17
  %12 = load i32, ptr %c.addr, align 4
  %cmp19 = icmp eq i32 %12, 43
  %conv = zext i1 %cmp19 to i32
  %mul20 = mul nsw i32 %conv, 62
  %add21 = add nsw i32 %add18, %mul20
  %13 = load i32, ptr %c.addr, align 4
  %cmp22 = icmp eq i32 %13, 47
  %conv23 = zext i1 %cmp22 to i32
  %mul24 = mul nsw i32 %conv23, 63
  %add25 = add nsw i32 %add21, %mul24
  ret i32 %add25
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
