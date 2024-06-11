; ModuleID = '/home/javier/Galapagos/functions/ffmpeg/variants/c/3_weight_3.bc'
source_filename = "/home/javier/Galapagos/functions/ffmpeg/variants/c/3_weight_3.c"
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
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %1 = load i32, ptr %i.addr, align 4
  %2 = load i32, ptr %offset.addr, align 4
  %mul = mul nsw i32 2, %2
  %cmp1 = icmp slt i32 %1, %mul
  br i1 %cmp1, label %cond.true, label %cond.false

cond.true:                                        ; preds = %if.then
  %3 = load i32, ptr %i.addr, align 4
  %tobool = icmp ne i32 %3, 0
  %4 = zext i1 %tobool to i64
  %cond = select i1 %tobool, i32 5, i32 3
  br label %cond.end12

cond.false:                                       ; preds = %if.then
  %5 = load i32, ptr %i.addr, align 4
  %6 = load i32, ptr %blen.addr, align 4
  %sub = sub nsw i32 %6, 1
  %7 = load i32, ptr %offset.addr, align 4
  %mul2 = mul nsw i32 2, %7
  %sub3 = sub nsw i32 %sub, %mul2
  %cmp4 = icmp sgt i32 %5, %sub3
  br i1 %cmp4, label %cond.true5, label %cond.false10

cond.true5:                                       ; preds = %cond.false
  %8 = load i32, ptr %blen.addr, align 4
  %sub6 = sub nsw i32 %8, 1
  %9 = load i32, ptr %i.addr, align 4
  %sub7 = sub nsw i32 %sub6, %9
  %tobool8 = icmp ne i32 %sub7, 0
  %10 = zext i1 %tobool8 to i64
  %cond9 = select i1 %tobool8, i32 5, i32 3
  br label %cond.end

cond.false10:                                     ; preds = %cond.false
  br label %cond.end

cond.end:                                         ; preds = %cond.false10, %cond.true5
  %cond11 = phi i32 [ %cond9, %cond.true5 ], [ 8, %cond.false10 ]
  br label %cond.end12

cond.end12:                                       ; preds = %cond.end, %cond.true
  %cond13 = phi i32 [ %cond, %cond.true ], [ %cond11, %cond.end ]
  store i32 %cond13, ptr %retval, align 4
  br label %return

if.else:                                          ; preds = %entry
  %11 = load i32, ptr %i.addr, align 4
  %12 = load i32, ptr %offset.addr, align 4
  %mul14 = mul nsw i32 2, %12
  %cmp15 = icmp slt i32 %11, %mul14
  br i1 %cmp15, label %cond.true16, label %cond.false22

cond.true16:                                      ; preds = %if.else
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
  br label %cond.end40

cond.false22:                                     ; preds = %if.else
  %16 = load i32, ptr %i.addr, align 4
  %17 = load i32, ptr %blen.addr, align 4
  %sub23 = sub nsw i32 %17, 1
  %18 = load i32, ptr %offset.addr, align 4
  %mul24 = mul nsw i32 2, %18
  %sub25 = sub nsw i32 %sub23, %mul24
  %cmp26 = icmp sgt i32 %16, %sub25
  br i1 %cmp26, label %cond.true27, label %cond.false37

cond.true27:                                      ; preds = %cond.false22
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
  br label %cond.end38

cond.false37:                                     ; preds = %cond.false22
  br label %cond.end38

cond.end38:                                       ; preds = %cond.false37, %cond.true27
  %cond39 = phi i32 [ %add36, %cond.true27 ], [ 8, %cond.false37 ]
  br label %cond.end40

cond.end40:                                       ; preds = %cond.end38, %cond.true16
  %cond41 = phi i32 [ %add21, %cond.true16 ], [ %cond39, %cond.end38 ]
  store i32 %cond41, ptr %retval, align 4
  br label %return

return:                                           ; preds = %cond.end40, %cond.end12
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
