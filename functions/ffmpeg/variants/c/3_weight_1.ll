; ModuleID = '/home/javier/Galapagos/functions/ffmpeg/variants/c/3_weight_1.bc'
source_filename = "/home/javier/Galapagos/functions/ffmpeg/variants/c/3_weight_1.c"
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
  %retval = alloca i32, align 4
  %i.addr = alloca i32, align 4
  %blen.addr = alloca i32, align 4
  %offset.addr = alloca i32, align 4
  store i32 %i, ptr %i.addr, align 4
  store i32 %blen, ptr %blen.addr, align 4
  store i32 %offset, ptr %offset.addr, align 4
  %0 = load i32, ptr %offset.addr, align 4
  %cmp = icmp eq i32 %0, 1
  br i1 %cmp, label %if.then, label %if.else13

if.then:                                          ; preds = %entry
  %1 = load i32, ptr %i.addr, align 4
  %2 = load i32, ptr %offset.addr, align 4
  %mul = mul nsw i32 2, %2
  %cmp1 = icmp slt i32 %1, %mul
  br i1 %cmp1, label %if.then2, label %if.else

if.then2:                                         ; preds = %if.then
  %3 = load i32, ptr %i.addr, align 4
  %cmp3 = icmp ne i32 %3, 0
  %4 = zext i1 %cmp3 to i64
  %cond = select i1 %cmp3, i32 5, i32 3
  store i32 %cond, ptr %retval, align 4
  br label %return

if.else:                                          ; preds = %if.then
  %5 = load i32, ptr %i.addr, align 4
  %6 = load i32, ptr %blen.addr, align 4
  %sub = sub nsw i32 %6, 1
  %7 = load i32, ptr %offset.addr, align 4
  %mul4 = mul nsw i32 2, %7
  %sub5 = sub nsw i32 %sub, %mul4
  %cmp6 = icmp sgt i32 %5, %sub5
  br i1 %cmp6, label %if.then7, label %if.else12

if.then7:                                         ; preds = %if.else
  %8 = load i32, ptr %blen.addr, align 4
  %sub8 = sub nsw i32 %8, 1
  %9 = load i32, ptr %i.addr, align 4
  %sub9 = sub nsw i32 %sub8, %9
  %cmp10 = icmp ne i32 %sub9, 0
  %10 = zext i1 %cmp10 to i64
  %cond11 = select i1 %cmp10, i32 5, i32 3
  store i32 %cond11, ptr %retval, align 4
  br label %return

if.else12:                                        ; preds = %if.else
  store i32 8, ptr %retval, align 4
  br label %return

if.else13:                                        ; preds = %entry
  %11 = load i32, ptr %i.addr, align 4
  %12 = load i32, ptr %offset.addr, align 4
  %mul14 = mul nsw i32 2, %12
  %cmp15 = icmp slt i32 %11, %mul14
  br i1 %cmp15, label %if.then16, label %if.else22

if.then16:                                        ; preds = %if.else13
  %13 = load i32, ptr %i.addr, align 4
  %mul17 = mul nsw i32 6, %13
  %14 = load i32, ptr %offset.addr, align 4
  %add = add nsw i32 %mul17, %14
  %sub18 = sub nsw i32 %add, 1
  %15 = load i32, ptr %offset.addr, align 4
  %mul19 = mul nsw i32 2, %15
  %sub20 = sub nsw i32 %mul19, 1
  %div = sdiv i32 %sub18, %sub20
  %add21 = add nsw i32 1, %div
  store i32 %add21, ptr %retval, align 4
  br label %return

if.else22:                                        ; preds = %if.else13
  %16 = load i32, ptr %i.addr, align 4
  %17 = load i32, ptr %blen.addr, align 4
  %sub23 = sub nsw i32 %17, 1
  %18 = load i32, ptr %offset.addr, align 4
  %mul24 = mul nsw i32 2, %18
  %sub25 = sub nsw i32 %sub23, %mul24
  %cmp26 = icmp sgt i32 %16, %sub25
  br i1 %cmp26, label %if.then27, label %if.else37

if.then27:                                        ; preds = %if.else22
  %19 = load i32, ptr %blen.addr, align 4
  %sub28 = sub nsw i32 %19, 1
  %20 = load i32, ptr %i.addr, align 4
  %sub29 = sub nsw i32 %sub28, %20
  %mul30 = mul nsw i32 6, %sub29
  %21 = load i32, ptr %offset.addr, align 4
  %add31 = add nsw i32 %mul30, %21
  %sub32 = sub nsw i32 %add31, 1
  %22 = load i32, ptr %offset.addr, align 4
  %mul33 = mul nsw i32 2, %22
  %sub34 = sub nsw i32 %mul33, 1
  %div35 = sdiv i32 %sub32, %sub34
  %add36 = add nsw i32 1, %div35
  store i32 %add36, ptr %retval, align 4
  br label %return

if.else37:                                        ; preds = %if.else22
  store i32 8, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.else37, %if.then27, %if.then16, %if.else12, %if.then7, %if.then2
  %23 = load i32, ptr %retval, align 4
  ret i32 %23
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
