; ModuleID = '/home/javier/Galapagos/functions/ffmpeg/variants/c/3_weight_7.bc'
source_filename = "/home/javier/Galapagos/functions/ffmpeg/variants/c/3_weight_7.c"
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
  %0 = load i32, ptr %i.addr, align 4
  %1 = load i32, ptr %offset.addr, align 4
  %mul = mul nsw i32 2, %1
  %cmp = icmp slt i32 %0, %mul
  br i1 %cmp, label %if.then, label %if.else7

if.then:                                          ; preds = %entry
  %2 = load i32, ptr %offset.addr, align 4
  %cmp1 = icmp eq i32 %2, 1
  br i1 %cmp1, label %if.then2, label %if.else

if.then2:                                         ; preds = %if.then
  %3 = load i32, ptr %i.addr, align 4
  %tobool = icmp ne i32 %3, 0
  %4 = zext i1 %tobool to i64
  %cond = select i1 %tobool, i32 5, i32 3
  store i32 %cond, ptr %retval, align 4
  br label %return

if.else:                                          ; preds = %if.then
  %5 = load i32, ptr %i.addr, align 4
  %mul3 = mul nsw i32 6, %5
  %6 = load i32, ptr %offset.addr, align 4
  %add = add nsw i32 %mul3, %6
  %sub = sub nsw i32 %add, 1
  %7 = load i32, ptr %offset.addr, align 4
  %mul4 = mul nsw i32 2, %7
  %sub5 = sub nsw i32 %mul4, 1
  %div = sdiv i32 %sub, %sub5
  %add6 = add nsw i32 1, %div
  store i32 %add6, ptr %retval, align 4
  br label %return

if.else7:                                         ; preds = %entry
  %8 = load i32, ptr %i.addr, align 4
  %9 = load i32, ptr %blen.addr, align 4
  %sub8 = sub nsw i32 %9, 1
  %10 = load i32, ptr %offset.addr, align 4
  %mul9 = mul nsw i32 2, %10
  %sub10 = sub nsw i32 %sub8, %mul9
  %cmp11 = icmp sgt i32 %8, %sub10
  br i1 %cmp11, label %if.then12, label %if.end

if.then12:                                        ; preds = %if.else7
  %11 = load i32, ptr %offset.addr, align 4
  %cmp13 = icmp eq i32 %11, 1
  br i1 %cmp13, label %if.then14, label %if.else19

if.then14:                                        ; preds = %if.then12
  %12 = load i32, ptr %blen.addr, align 4
  %sub15 = sub nsw i32 %12, 1
  %13 = load i32, ptr %i.addr, align 4
  %sub16 = sub nsw i32 %sub15, %13
  %tobool17 = icmp ne i32 %sub16, 0
  %14 = zext i1 %tobool17 to i64
  %cond18 = select i1 %tobool17, i32 5, i32 3
  store i32 %cond18, ptr %retval, align 4
  br label %return

if.else19:                                        ; preds = %if.then12
  %15 = load i32, ptr %blen.addr, align 4
  %sub20 = sub nsw i32 %15, 1
  %16 = load i32, ptr %i.addr, align 4
  %sub21 = sub nsw i32 %sub20, %16
  %mul22 = mul nsw i32 6, %sub21
  %17 = load i32, ptr %offset.addr, align 4
  %add23 = add nsw i32 %mul22, %17
  %sub24 = sub nsw i32 %add23, 1
  %18 = load i32, ptr %offset.addr, align 4
  %mul25 = mul nsw i32 2, %18
  %sub26 = sub nsw i32 %mul25, 1
  %div27 = sdiv i32 %sub24, %sub26
  %add28 = add nsw i32 1, %div27
  store i32 %add28, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %if.else7
  br label %if.end29

if.end29:                                         ; preds = %if.end
  store i32 8, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end29, %if.else19, %if.then14, %if.else, %if.then2
  %19 = load i32, ptr %retval, align 4
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
