; ModuleID = '/home/javier/Galapagos/functions/ffmpeg/variants/c/3_weight_6.bc'
source_filename = "/home/javier/Galapagos/functions/ffmpeg/variants/c/3_weight_6.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @weight(i32 noundef 0, i32 noundef 0, i32 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @weight(i32 noundef %i, i32 noundef %blen, i32 noundef %offset) #0 {
entry:
  %i.addr = alloca i32, align 4
  %blen.addr = alloca i32, align 4
  %offset.addr = alloca i32, align 4
  %result = alloca i32, align 4
  store i32 %i, ptr %i.addr, align 4
  store i32 %blen, ptr %blen.addr, align 4
  store i32 %offset, ptr %offset.addr, align 4
  %0 = load i32, ptr %i.addr, align 4
  %1 = load i32, ptr %offset.addr, align 4
  %mul = mul nsw i32 2, %1
  %cmp = icmp slt i32 %0, %mul
  br i1 %cmp, label %if.then, label %if.else8

if.then:                                          ; preds = %entry
  %2 = load i32, ptr %offset.addr, align 4
  %cmp1 = icmp eq i32 %2, 1
  br i1 %cmp1, label %if.then2, label %if.else

if.then2:                                         ; preds = %if.then
  %3 = load i32, ptr %i.addr, align 4
  %cmp3 = icmp ne i32 %3, 0
  %4 = zext i1 %cmp3 to i64
  %cond = select i1 %cmp3, i32 5, i32 3
  store i32 %cond, ptr %result, align 4
  br label %if.end

if.else:                                          ; preds = %if.then
  %5 = load i32, ptr %i.addr, align 4
  %mul4 = mul nsw i32 6, %5
  %6 = load i32, ptr %offset.addr, align 4
  %add = add nsw i32 %mul4, %6
  %sub = sub nsw i32 %add, 1
  %7 = load i32, ptr %offset.addr, align 4
  %mul5 = mul nsw i32 2, %7
  %sub6 = sub nsw i32 %mul5, 1
  %div = sdiv i32 %sub, %sub6
  %add7 = add nsw i32 1, %div
  store i32 %add7, ptr %result, align 4
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then2
  br label %if.end33

if.else8:                                         ; preds = %entry
  %8 = load i32, ptr %i.addr, align 4
  %9 = load i32, ptr %blen.addr, align 4
  %sub9 = sub nsw i32 %9, 1
  %10 = load i32, ptr %offset.addr, align 4
  %mul10 = mul nsw i32 2, %10
  %sub11 = sub nsw i32 %sub9, %mul10
  %cmp12 = icmp sgt i32 %8, %sub11
  br i1 %cmp12, label %if.then13, label %if.else31

if.then13:                                        ; preds = %if.else8
  %11 = load i32, ptr %offset.addr, align 4
  %cmp14 = icmp eq i32 %11, 1
  br i1 %cmp14, label %if.then15, label %if.else20

if.then15:                                        ; preds = %if.then13
  %12 = load i32, ptr %blen.addr, align 4
  %sub16 = sub nsw i32 %12, 1
  %13 = load i32, ptr %i.addr, align 4
  %sub17 = sub nsw i32 %sub16, %13
  %cmp18 = icmp ne i32 %sub17, 0
  %14 = zext i1 %cmp18 to i64
  %cond19 = select i1 %cmp18, i32 5, i32 3
  store i32 %cond19, ptr %result, align 4
  br label %if.end30

if.else20:                                        ; preds = %if.then13
  %15 = load i32, ptr %blen.addr, align 4
  %sub21 = sub nsw i32 %15, 1
  %16 = load i32, ptr %i.addr, align 4
  %sub22 = sub nsw i32 %sub21, %16
  %mul23 = mul nsw i32 6, %sub22
  %17 = load i32, ptr %offset.addr, align 4
  %add24 = add nsw i32 %mul23, %17
  %sub25 = sub nsw i32 %add24, 1
  %18 = load i32, ptr %offset.addr, align 4
  %mul26 = mul nsw i32 2, %18
  %sub27 = sub nsw i32 %mul26, 1
  %div28 = sdiv i32 %sub25, %sub27
  %add29 = add nsw i32 1, %div28
  store i32 %add29, ptr %result, align 4
  br label %if.end30

if.end30:                                         ; preds = %if.else20, %if.then15
  br label %if.end32

if.else31:                                        ; preds = %if.else8
  store i32 8, ptr %result, align 4
  br label %if.end32

if.end32:                                         ; preds = %if.else31, %if.end30
  br label %if.end33

if.end33:                                         ; preds = %if.end32, %if.end
  %19 = load i32, ptr %result, align 4
  ret i32 %19
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
