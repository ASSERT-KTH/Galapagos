; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/c/4_val_seg_2.bc'
source_filename = "/home/javier/Galapagos/functions/alsa-lib/variants/c/4_val_seg_2.c"
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
  %shr = ashr i32 %0, 12
  %and = and i32 %shr, 15
  %tobool = icmp ne i32 %and, 0
  br i1 %tobool, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %1 = load i32, ptr %r, align 4
  %add = add nsw i32 %1, 6
  store i32 %add, ptr %r, align 4
  br label %if.end12

if.else:                                          ; preds = %entry
  %2 = load i32, ptr %val.addr, align 4
  %shr1 = ashr i32 %2, 8
  %and2 = and i32 %shr1, 15
  %tobool3 = icmp ne i32 %and2, 0
  br i1 %tobool3, label %if.then4, label %if.end11

if.then4:                                         ; preds = %if.else
  %3 = load i32, ptr %r, align 4
  %add5 = add nsw i32 %3, 4
  store i32 %add5, ptr %r, align 4
  %4 = load i32, ptr %val.addr, align 4
  %shr6 = ashr i32 %4, 4
  %and7 = and i32 %shr6, 3
  %tobool8 = icmp ne i32 %and7, 0
  br i1 %tobool8, label %if.then9, label %if.end

if.then9:                                         ; preds = %if.then4
  %5 = load i32, ptr %r, align 4
  %add10 = add nsw i32 %5, 2
  store i32 %add10, ptr %r, align 4
  br label %if.end

if.end:                                           ; preds = %if.then9, %if.then4
  br label %if.end11

if.end11:                                         ; preds = %if.end, %if.else
  br label %if.end12

if.end12:                                         ; preds = %if.end11, %if.then
  %6 = load i32, ptr %val.addr, align 4
  %shr13 = ashr i32 %6, 8
  %and14 = and i32 %shr13, 2
  %tobool15 = icmp ne i32 %and14, 0
  br i1 %tobool15, label %if.then16, label %if.end18

if.then16:                                        ; preds = %if.end12
  %7 = load i32, ptr %r, align 4
  %add17 = add nsw i32 %7, 1
  store i32 %add17, ptr %r, align 4
  br label %if.end18

if.end18:                                         ; preds = %if.then16, %if.end12
  %8 = load i32, ptr %r, align 4
  ret i32 %8
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
