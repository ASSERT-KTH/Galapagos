; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/c/4_val_seg_8.bc'
source_filename = "/home/javier/Galapagos/functions/alsa-lib/variants/c/4_val_seg_8.c"
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
  switch i32 %and, label %sw.default [
    i32 240, label %sw.bb
  ]

sw.bb:                                            ; preds = %entry
  %2 = load i32, ptr %val.addr, align 4
  %shr1 = ashr i32 %2, 4
  store i32 %shr1, ptr %val.addr, align 4
  %3 = load i32, ptr %r, align 4
  %add = add nsw i32 %3, 4
  store i32 %add, ptr %r, align 4
  br label %sw.epilog

sw.default:                                       ; preds = %entry
  br label %sw.epilog

sw.epilog:                                        ; preds = %sw.default, %sw.bb
  %4 = load i32, ptr %val.addr, align 4
  %and2 = and i32 %4, 12
  switch i32 %and2, label %sw.default6 [
    i32 12, label %sw.bb3
  ]

sw.bb3:                                           ; preds = %sw.epilog
  %5 = load i32, ptr %val.addr, align 4
  %shr4 = ashr i32 %5, 2
  store i32 %shr4, ptr %val.addr, align 4
  %6 = load i32, ptr %r, align 4
  %add5 = add nsw i32 %6, 2
  store i32 %add5, ptr %r, align 4
  br label %sw.epilog7

sw.default6:                                      ; preds = %sw.epilog
  br label %sw.epilog7

sw.epilog7:                                       ; preds = %sw.default6, %sw.bb3
  %7 = load i32, ptr %val.addr, align 4
  %and8 = and i32 %7, 2
  %tobool = icmp ne i32 %and8, 0
  br i1 %tobool, label %if.then, label %if.end

if.then:                                          ; preds = %sw.epilog7
  %8 = load i32, ptr %r, align 4
  %add9 = add nsw i32 %8, 1
  store i32 %add9, ptr %r, align 4
  br label %if.end

if.end:                                           ; preds = %if.then, %sw.epilog7
  %9 = load i32, ptr %r, align 4
  ret i32 %9
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
