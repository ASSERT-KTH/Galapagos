; ModuleID = '/home/javier/Galapagos/functions/ffmpeg/variants/c/3_weight_4.bc'
source_filename = "/home/javier/Galapagos/functions/ffmpeg/variants/c/3_weight_4.c"
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
  %ret = alloca i32, align 4
  store i32 %i, ptr %i.addr, align 4
  store i32 %blen, ptr %blen.addr, align 4
  store i32 %offset, ptr %offset.addr, align 4
  store i32 8, ptr %ret, align 4
  %0 = load i32, ptr %i.addr, align 4
  %1 = load i32, ptr %offset.addr, align 4
  %mul = mul nsw i32 2, %1
  %cmp = icmp slt i32 %0, %mul
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %2 = load i32, ptr %offset.addr, align 4
  %cmp1 = icmp eq i32 %2, 1
  br i1 %cmp1, label %cond.true, label %cond.false

cond.true:                                        ; preds = %if.then
  %3 = load i32, ptr %i.addr, align 4
  %tobool = icmp ne i32 %3, 0
  %4 = zext i1 %tobool to i64
  %cond = select i1 %tobool, i32 5, i32 3
  br label %cond.end

cond.false:                                       ; preds = %if.then
  %5 = load i32, ptr %i.addr, align 4
  %mul2 = mul nsw i32 6, %5
  %6 = load i32, ptr %offset.addr, align 4
  %add = add nsw i32 %mul2, %6
  %sub = sub nsw i32 %add, 1
  %7 = load i32, ptr %offset.addr, align 4
  %mul3 = mul nsw i32 2, %7
  %sub4 = sub nsw i32 %mul3, 1
  %div = sdiv i32 %sub, %sub4
  %add5 = add nsw i32 1, %div
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond6 = phi i32 [ %cond, %cond.true ], [ %add5, %cond.false ]
  store i32 %cond6, ptr %ret, align 4
  br label %if.end30

if.else:                                          ; preds = %entry
  %8 = load i32, ptr %i.addr, align 4
  %9 = load i32, ptr %blen.addr, align 4
  %sub7 = sub nsw i32 %9, 1
  %10 = load i32, ptr %offset.addr, align 4
  %mul8 = mul nsw i32 2, %10
  %sub9 = sub nsw i32 %sub7, %mul8
  %cmp10 = icmp sgt i32 %8, %sub9
  br i1 %cmp10, label %if.then11, label %if.end

if.then11:                                        ; preds = %if.else
  %11 = load i32, ptr %offset.addr, align 4
  %cmp12 = icmp eq i32 %11, 1
  br i1 %cmp12, label %cond.true13, label %cond.false18

cond.true13:                                      ; preds = %if.then11
  %12 = load i32, ptr %blen.addr, align 4
  %sub14 = sub nsw i32 %12, 1
  %13 = load i32, ptr %i.addr, align 4
  %sub15 = sub nsw i32 %sub14, %13
  %tobool16 = icmp ne i32 %sub15, 0
  %14 = zext i1 %tobool16 to i64
  %cond17 = select i1 %tobool16, i32 5, i32 3
  br label %cond.end28

cond.false18:                                     ; preds = %if.then11
  %15 = load i32, ptr %blen.addr, align 4
  %sub19 = sub nsw i32 %15, 1
  %16 = load i32, ptr %i.addr, align 4
  %sub20 = sub nsw i32 %sub19, %16
  %mul21 = mul nsw i32 6, %sub20
  %17 = load i32, ptr %offset.addr, align 4
  %add22 = add nsw i32 %mul21, %17
  %sub23 = sub nsw i32 %add22, 1
  %18 = load i32, ptr %offset.addr, align 4
  %mul24 = mul nsw i32 2, %18
  %sub25 = sub nsw i32 %mul24, 1
  %div26 = sdiv i32 %sub23, %sub25
  %add27 = add nsw i32 1, %div26
  br label %cond.end28

cond.end28:                                       ; preds = %cond.false18, %cond.true13
  %cond29 = phi i32 [ %cond17, %cond.true13 ], [ %add27, %cond.false18 ]
  store i32 %cond29, ptr %ret, align 4
  br label %if.end

if.end:                                           ; preds = %cond.end28, %if.else
  br label %if.end30

if.end30:                                         ; preds = %if.end, %cond.end
  %19 = load i32, ptr %ret, align 4
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
