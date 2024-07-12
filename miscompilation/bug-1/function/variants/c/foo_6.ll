; ModuleID = '/home/javier/Galapagos/miscompilation/bug-1/function/variants/c/foo_6.bc'
source_filename = "/home/javier/Galapagos/miscompilation/bug-1/function/variants/c/foo_6.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@b = dso_local global i16 5, align 2
@a = dso_local global i32 0, align 4
@c = dso_local global i16 0, align 2
@stdout = external global ptr, align 8
@l = dso_local global i16 0, align 2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @foo() #0 {
entry:
  %e = alloca i16, align 2
  %f = alloca i16, align 2
  %g = alloca i8, align 1
  %h = alloca i64, align 8
  %i = alloca i16, align 2
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %l = alloca i16, align 2
  store i16 -1, ptr %e, align 2
  store i8 25, ptr %g, align 1
  store i64 0, ptr %h, align 8
  %0 = load i32, ptr @a, align 4
  %cmp = icmp ne i32 %0, 0
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i64 -1, ptr %h, align 8
  store i8 0, ptr %g, align 1
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %1 = load i8, ptr %g, align 1
  %conv = sext i8 %1 to i32
  %not = xor i32 %conv, -1
  %conv1 = trunc i32 %not to i16
  store i16 %conv1, ptr %i, align 2
  %2 = load i8, ptr %g, align 1
  %conv2 = sext i8 %2 to i32
  store i32 %conv2, ptr %j, align 4
  %3 = load i64, ptr %h, align 8
  %4 = load i16, ptr %i, align 2
  %conv3 = sext i16 %4 to i32
  %5 = load i32, ptr %j, align 4
  %or = or i32 583, %5
  %or4 = or i32 %conv3, %or
  %conv5 = zext i32 %or4 to i64
  %or6 = or i64 %3, %conv5
  %6 = load i8, ptr %g, align 1
  %conv7 = sext i8 %6 to i64
  %and = and i64 %conv7, 5
  %not8 = xor i64 %and, -1
  %7 = load i16, ptr %e, align 2
  %conv9 = sext i16 %7 to i64
  %div = sdiv i64 %not8, %conv9
  %not10 = xor i64 %div, -1
  %xor = xor i64 %or6, %not10
  %conv11 = trunc i64 %xor to i16
  store i16 %conv11, ptr %f, align 2
  %8 = load i16, ptr @b, align 2
  %conv12 = sext i16 %8 to i32
  %cmp13 = icmp ne i32 %conv12, 0
  br i1 %cmp13, label %if.then15, label %if.end24

if.then15:                                        ; preds = %if.end
  %9 = load i16, ptr %f, align 2
  %conv16 = zext i16 %9 to i64
  %sub = sub i64 8, %conv16
  %div17 = udiv i64 22, %sub
  %conv18 = trunc i64 %div17 to i16
  store i16 %conv18, ptr @c, align 2
  %10 = load i16, ptr %f, align 2
  %conv19 = zext i16 %10 to i32
  %cmp20 = icmp ne i32 %conv19, 0
  br i1 %cmp20, label %if.then22, label %if.end23

if.then22:                                        ; preds = %if.then15
  %11 = load ptr, ptr @stdout, align 8
  %call = call i32 @putc(i32 noundef 0, ptr noundef %11)
  br label %if.end23

if.end23:                                         ; preds = %if.then22, %if.then15
  br label %if.end24

if.end24:                                         ; preds = %if.end23, %if.end
  %12 = load i64, ptr %h, align 8
  %13 = load i16, ptr @c, align 2
  %conv25 = sext i16 %13 to i64
  %rem = srem i64 %12, %conv25
  %conv26 = trunc i64 %rem to i32
  store i32 %conv26, ptr %k, align 4
  %14 = load i16, ptr %f, align 2
  %conv27 = zext i16 %14 to i64
  %xor28 = xor i64 %conv27, 5
  %conv29 = trunc i64 %xor28 to i16
  store i16 %conv29, ptr %l, align 2
  %15 = load i16, ptr %l, align 2
  %conv30 = sext i16 %15 to i32
  %cmp31 = icmp ne i32 %conv30, 0
  br i1 %cmp31, label %if.then33, label %if.end34

if.then33:                                        ; preds = %if.end24
  %16 = load i32, ptr %k, align 4
  store i32 %16, ptr @a, align 4
  br label %if.end34

if.end34:                                         ; preds = %if.then33, %if.end24
  %17 = load i32, ptr @a, align 4
  %tobool = icmp ne i32 %17, 0
  %18 = zext i1 %tobool to i64
  %cond = select i1 %tobool, i32 1, i32 0
  ret i32 %cond
}

declare i32 @putc(i32 noundef, ptr noundef) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @foo()
  ret i32 0
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 17.0.0 (git@github.com:llvm/llvm-project.git 1a7a00bdc99fa2b2ca19ecd2d1069991b3c1006b)"}
