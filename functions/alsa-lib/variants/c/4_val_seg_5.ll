; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/c/4_val_seg_5.bc'
source_filename = "/home/javier/Galapagos/functions/alsa-lib/variants/c/4_val_seg_5.c"
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
  %and = and i32 %1, 240
  %tobool = icmp ne i32 %and, 0
  br i1 %tobool, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %2 = load i32, ptr %r, align 4
  %add = add nsw i32 %2, 4
  store i32 %add, ptr %r, align 4
  %3 = load i32, ptr %val.addr, align 4
  %shr1 = ashr i32 %3, 4
  store i32 %shr1, ptr %val.addr, align 4
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %4 = load i32, ptr %val.addr, align 4
  %and2 = and i32 %4, 12
  %tobool3 = icmp ne i32 %and2, 0
  br i1 %tobool3, label %cond.true, label %cond.false

cond.true:                                        ; preds = %if.end
  %5 = load i32, ptr %val.addr, align 4
  %and4 = and i32 %5, 12
  %shr5 = ashr i32 %and4, 2
  br label %cond.end

cond.false:                                       ; preds = %if.end
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %shr5, %cond.true ], [ 0, %cond.false ]
  %6 = load i32, ptr %r, align 4
  %add6 = add nsw i32 %6, %cond
  store i32 %add6, ptr %r, align 4
  %7 = load i32, ptr %val.addr, align 4
  %and7 = and i32 %7, 3
  %tobool8 = icmp ne i32 %and7, 0
  br i1 %tobool8, label %cond.true9, label %cond.false12

cond.true9:                                       ; preds = %cond.end
  %8 = load i32, ptr %val.addr, align 4
  %and10 = and i32 %8, 2
  %shr11 = ashr i32 %and10, 1
  br label %cond.end13

cond.false12:                                     ; preds = %cond.end
  br label %cond.end13

cond.end13:                                       ; preds = %cond.false12, %cond.true9
  %cond14 = phi i32 [ %shr11, %cond.true9 ], [ 0, %cond.false12 ]
  %9 = load i32, ptr %r, align 4
  %add15 = add nsw i32 %9, %cond14
  store i32 %add15, ptr %r, align 4
  %10 = load i32, ptr %r, align 4
  ret i32 %10
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
