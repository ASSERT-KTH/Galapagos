; ModuleID = '/home/javier/Galapagos/functions/ffmpeg/variants/c/4_int_sin_0.bc'
source_filename = "/home/javier/Galapagos/functions/ffmpeg/variants/c/4_int_sin_0.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i64 @int_sin(i64 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @int_sin(i64 noundef %a) #0 {
entry:
  %a.addr = alloca i64, align 8
  %a2 = alloca i64, align 8
  %res = alloca i64, align 8
  %i = alloca i32, align 4
  store i64 %a, ptr %a.addr, align 8
  store i64 0, ptr %res, align 8
  %0 = load i64, ptr %a.addr, align 8
  %cmp = icmp slt i64 %0, 0
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %1 = load i64, ptr %a.addr, align 8
  %sub = sub nsw i64 3294199, %1
  store i64 %sub, ptr %a.addr, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %2 = load i64, ptr %a.addr, align 8
  %rem = srem i64 %2, 6588398
  store i64 %rem, ptr %a.addr, align 8
  %3 = load i64, ptr %a.addr, align 8
  %cmp1 = icmp sge i64 %3, 4941298
  br i1 %cmp1, label %if.then2, label %if.end4

if.then2:                                         ; preds = %if.end
  %4 = load i64, ptr %a.addr, align 8
  %sub3 = sub nsw i64 %4, 6588398
  store i64 %sub3, ptr %a.addr, align 8
  br label %if.end4

if.end4:                                          ; preds = %if.then2, %if.end
  %5 = load i64, ptr %a.addr, align 8
  %cmp5 = icmp sge i64 %5, 1647099
  br i1 %cmp5, label %if.then6, label %if.end8

if.then6:                                         ; preds = %if.end4
  %6 = load i64, ptr %a.addr, align 8
  %sub7 = sub nsw i64 3294199, %6
  store i64 %sub7, ptr %a.addr, align 8
  br label %if.end8

if.end8:                                          ; preds = %if.then6, %if.end4
  %7 = load i64, ptr %a.addr, align 8
  %8 = load i64, ptr %a.addr, align 8
  %mul = mul nsw i64 %7, %8
  %shr = ashr i64 %mul, 20
  store i64 %shr, ptr %a2, align 8
  store i32 2, ptr %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %if.end8
  %9 = load i32, ptr %i, align 4
  %cmp9 = icmp slt i32 %9, 11
  br i1 %cmp9, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %10 = load i64, ptr %a.addr, align 8
  %11 = load i64, ptr %res, align 8
  %add = add nsw i64 %11, %10
  store i64 %add, ptr %res, align 8
  %12 = load i64, ptr %a.addr, align 8
  %13 = load i64, ptr %a2, align 8
  %mul10 = mul nsw i64 %12, %13
  %sub11 = sub nsw i64 0, %mul10
  %14 = load i32, ptr %i, align 4
  %15 = load i32, ptr %i, align 4
  %add12 = add nsw i32 %15, 1
  %mul13 = mul nsw i32 %14, %add12
  %conv = sext i32 %mul13 to i64
  %div = sdiv i64 %sub11, %conv
  store i64 %div, ptr %a.addr, align 8
  %16 = load i64, ptr %a.addr, align 8
  %shr14 = ashr i64 %16, 20
  store i64 %shr14, ptr %a.addr, align 8
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %17 = load i32, ptr %i, align 4
  %add15 = add nsw i32 %17, 2
  store i32 %add15, ptr %i, align 4
  br label %for.cond, !llvm.loop !6

for.end:                                          ; preds = %for.cond
  %18 = load i64, ptr %res, align 8
  %add16 = add nsw i64 %18, 8
  %shr17 = ashr i64 %add16, 4
  ret i64 %shr17
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
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
