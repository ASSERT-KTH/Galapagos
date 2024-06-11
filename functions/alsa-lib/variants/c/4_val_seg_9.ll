; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/c/4_val_seg_9.bc'
source_filename = "/home/javier/Galapagos/functions/alsa-lib/variants/c/4_val_seg_9.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @val_seg(i32 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @val_seg(i32 noundef %val) #0 {
entry:
  %val.addr = alloca i32, align 4
  %r = alloca i32, align 4
  store i32 %val, ptr %val.addr, align 4
  store i32 1, ptr %r, align 4
  %0 = load i32, ptr %val.addr, align 4
  %shr = ashr i32 %0, 8
  store i32 %shr, ptr %val.addr, align 4
  %1 = load i32, ptr %val.addr, align 4
  %cmp = icmp slt i32 %1, 16
  br i1 %cmp, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  br label %cond.end11

cond.false:                                       ; preds = %entry
  %2 = load i32, ptr %val.addr, align 4
  %cmp1 = icmp slt i32 %2, 32
  br i1 %cmp1, label %cond.true2, label %cond.false3

cond.true2:                                       ; preds = %cond.false
  br label %cond.end9

cond.false3:                                      ; preds = %cond.false
  %3 = load i32, ptr %val.addr, align 4
  %cmp4 = icmp slt i32 %3, 64
  br i1 %cmp4, label %cond.true5, label %cond.false6

cond.true5:                                       ; preds = %cond.false3
  br label %cond.end

cond.false6:                                      ; preds = %cond.false3
  %4 = load i32, ptr %val.addr, align 4
  %cmp7 = icmp slt i32 %4, 128
  %5 = zext i1 %cmp7 to i64
  %cond = select i1 %cmp7, i32 3, i32 4
  br label %cond.end

cond.end:                                         ; preds = %cond.false6, %cond.true5
  %cond8 = phi i32 [ 2, %cond.true5 ], [ %cond, %cond.false6 ]
  br label %cond.end9

cond.end9:                                        ; preds = %cond.end, %cond.true2
  %cond10 = phi i32 [ 1, %cond.true2 ], [ %cond8, %cond.end ]
  br label %cond.end11

cond.end11:                                       ; preds = %cond.end9, %cond.true
  %cond12 = phi i32 [ 0, %cond.true ], [ %cond10, %cond.end9 ]
  %6 = load i32, ptr %r, align 4
  %add = add nsw i32 %6, %cond12
  store i32 %add, ptr %r, align 4
  %7 = load i32, ptr %val.addr, align 4
  %cmp13 = icmp slt i32 %7, 16
  br i1 %cmp13, label %cond.true14, label %cond.false15

cond.true14:                                      ; preds = %cond.end11
  br label %cond.end28

cond.false15:                                     ; preds = %cond.end11
  %8 = load i32, ptr %val.addr, align 4
  %cmp16 = icmp slt i32 %8, 32
  br i1 %cmp16, label %cond.true17, label %cond.false18

cond.true17:                                      ; preds = %cond.false15
  br label %cond.end26

cond.false18:                                     ; preds = %cond.false15
  %9 = load i32, ptr %val.addr, align 4
  %cmp19 = icmp slt i32 %9, 64
  br i1 %cmp19, label %cond.true20, label %cond.false21

cond.true20:                                      ; preds = %cond.false18
  br label %cond.end24

cond.false21:                                     ; preds = %cond.false18
  %10 = load i32, ptr %val.addr, align 4
  %cmp22 = icmp slt i32 %10, 128
  %11 = zext i1 %cmp22 to i64
  %cond23 = select i1 %cmp22, i32 3, i32 4
  br label %cond.end24

cond.end24:                                       ; preds = %cond.false21, %cond.true20
  %cond25 = phi i32 [ 2, %cond.true20 ], [ %cond23, %cond.false21 ]
  br label %cond.end26

cond.end26:                                       ; preds = %cond.end24, %cond.true17
  %cond27 = phi i32 [ 1, %cond.true17 ], [ %cond25, %cond.end24 ]
  br label %cond.end28

cond.end28:                                       ; preds = %cond.end26, %cond.true14
  %cond29 = phi i32 [ 0, %cond.true14 ], [ %cond27, %cond.end26 ]
  %12 = load i32, ptr %val.addr, align 4
  %shr30 = ashr i32 %12, %cond29
  store i32 %shr30, ptr %val.addr, align 4
  %13 = load i32, ptr %val.addr, align 4
  %cmp31 = icmp slt i32 %13, 2
  br i1 %cmp31, label %cond.true32, label %cond.false33

cond.true32:                                      ; preds = %cond.end28
  br label %cond.end41

cond.false33:                                     ; preds = %cond.end28
  %14 = load i32, ptr %val.addr, align 4
  %cmp34 = icmp slt i32 %14, 4
  br i1 %cmp34, label %cond.true35, label %cond.false36

cond.true35:                                      ; preds = %cond.false33
  br label %cond.end39

cond.false36:                                     ; preds = %cond.false33
  %15 = load i32, ptr %val.addr, align 4
  %cmp37 = icmp slt i32 %15, 6
  %16 = zext i1 %cmp37 to i64
  %cond38 = select i1 %cmp37, i32 2, i32 3
  br label %cond.end39

cond.end39:                                       ; preds = %cond.false36, %cond.true35
  %cond40 = phi i32 [ 1, %cond.true35 ], [ %cond38, %cond.false36 ]
  br label %cond.end41

cond.end41:                                       ; preds = %cond.end39, %cond.true32
  %cond42 = phi i32 [ 0, %cond.true32 ], [ %cond40, %cond.end39 ]
  %17 = load i32, ptr %r, align 4
  %add43 = add nsw i32 %17, %cond42
  store i32 %add43, ptr %r, align 4
  %18 = load i32, ptr %r, align 4
  ret i32 %18
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
