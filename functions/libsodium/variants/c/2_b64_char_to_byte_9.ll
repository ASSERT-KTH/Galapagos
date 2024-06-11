; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/c/2_b64_char_to_byte_9.bc'
source_filename = "/home/javier/Galapagos/functions/libsodium/variants/c/2_b64_char_to_byte_9.c"
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
  br i1 %cmp, label %land.lhs.true, label %cond.false

land.lhs.true:                                    ; preds = %entry
  %1 = load i32, ptr %c.addr, align 4
  %cmp1 = icmp sle i32 %1, 90
  br i1 %cmp1, label %cond.true, label %cond.false

cond.true:                                        ; preds = %land.lhs.true
  %2 = load i32, ptr %c.addr, align 4
  %sub = sub nsw i32 %2, 65
  br label %cond.end24

cond.false:                                       ; preds = %land.lhs.true, %entry
  %3 = load i32, ptr %c.addr, align 4
  %cmp2 = icmp sge i32 %3, 97
  br i1 %cmp2, label %land.lhs.true3, label %cond.false7

land.lhs.true3:                                   ; preds = %cond.false
  %4 = load i32, ptr %c.addr, align 4
  %cmp4 = icmp sle i32 %4, 122
  br i1 %cmp4, label %cond.true5, label %cond.false7

cond.true5:                                       ; preds = %land.lhs.true3
  %5 = load i32, ptr %c.addr, align 4
  %sub6 = sub nsw i32 %5, 97
  %add = add nsw i32 %sub6, 26
  br label %cond.end22

cond.false7:                                      ; preds = %land.lhs.true3, %cond.false
  %6 = load i32, ptr %c.addr, align 4
  %cmp8 = icmp sge i32 %6, 48
  br i1 %cmp8, label %land.lhs.true9, label %cond.false14

land.lhs.true9:                                   ; preds = %cond.false7
  %7 = load i32, ptr %c.addr, align 4
  %cmp10 = icmp sle i32 %7, 57
  br i1 %cmp10, label %cond.true11, label %cond.false14

cond.true11:                                      ; preds = %land.lhs.true9
  %8 = load i32, ptr %c.addr, align 4
  %sub12 = sub nsw i32 %8, 48
  %add13 = add nsw i32 %sub12, 52
  br label %cond.end20

cond.false14:                                     ; preds = %land.lhs.true9, %cond.false7
  %9 = load i32, ptr %c.addr, align 4
  %cmp15 = icmp eq i32 %9, 43
  br i1 %cmp15, label %cond.true16, label %cond.false17

cond.true16:                                      ; preds = %cond.false14
  br label %cond.end

cond.false17:                                     ; preds = %cond.false14
  %10 = load i32, ptr %c.addr, align 4
  %cmp18 = icmp eq i32 %10, 47
  %11 = zext i1 %cmp18 to i64
  %cond = select i1 %cmp18, i32 63, i32 0
  br label %cond.end

cond.end:                                         ; preds = %cond.false17, %cond.true16
  %cond19 = phi i32 [ 62, %cond.true16 ], [ %cond, %cond.false17 ]
  br label %cond.end20

cond.end20:                                       ; preds = %cond.end, %cond.true11
  %cond21 = phi i32 [ %add13, %cond.true11 ], [ %cond19, %cond.end ]
  br label %cond.end22

cond.end22:                                       ; preds = %cond.end20, %cond.true5
  %cond23 = phi i32 [ %add, %cond.true5 ], [ %cond21, %cond.end20 ]
  br label %cond.end24

cond.end24:                                       ; preds = %cond.end22, %cond.true
  %cond25 = phi i32 [ %sub, %cond.true ], [ %cond23, %cond.end22 ]
  ret i32 %cond25
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
