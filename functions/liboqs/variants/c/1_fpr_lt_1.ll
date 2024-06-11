; ModuleID = '/home/javier/Galapagos/functions/liboqs/variants/c/1_fpr_lt_1.bc'
source_filename = "/home/javier/Galapagos/functions/liboqs/variants/c/1_fpr_lt_1.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @fpr_lt(i64 noundef %x, i64 noundef %y) #0 {
entry:
  %retval = alloca i32, align 4
  %x.addr = alloca i64, align 8
  %y.addr = alloca i64, align 8
  %sx = alloca i64, align 8
  %sy = alloca i64, align 8
  store i64 %x, ptr %x.addr, align 8
  store i64 %y, ptr %y.addr, align 8
  %0 = load i64, ptr %x.addr, align 8
  store i64 %0, ptr %sx, align 8
  %1 = load i64, ptr %y.addr, align 8
  store i64 %1, ptr %sy, align 8
  %2 = load i64, ptr %sx, align 8
  %cmp = icmp sge i64 %2, 0
  %conv = zext i1 %cmp to i32
  %3 = load i64, ptr %sy, align 8
  %cmp1 = icmp sge i64 %3, 0
  %conv2 = zext i1 %cmp1 to i32
  %cmp3 = icmp eq i32 %conv, %conv2
  br i1 %cmp3, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %4 = load i64, ptr %sx, align 8
  %5 = load i64, ptr %sy, align 8
  %cmp5 = icmp slt i64 %4, %5
  %conv6 = zext i1 %cmp5 to i32
  store i32 %conv6, ptr %retval, align 4
  br label %return

if.else:                                          ; preds = %entry
  %6 = load i64, ptr %sx, align 8
  %cmp7 = icmp slt i64 %6, 0
  %conv8 = zext i1 %cmp7 to i32
  store i32 %conv8, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.else, %if.then
  %7 = load i32, ptr %retval, align 4
  ret i32 %7
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @fpr_lt(i64 noundef 0, i64 noundef 0)
  ret i32 0
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
