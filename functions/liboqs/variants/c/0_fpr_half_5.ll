; ModuleID = '/home/javier/Galapagos/functions/liboqs/variants/c/0_fpr_half_5.bc'
source_filename = "/home/javier/Galapagos/functions/liboqs/variants/c/0_fpr_half_5.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i64 @fpr_half(i64 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @fpr_half(i64 noundef %x) #0 {
entry:
  %retval = alloca i64, align 8
  %x.addr = alloca i64, align 8
  %exp_mask = alloca i64, align 8
  store i64 %x, ptr %x.addr, align 8
  store i64 9218868437227405312, ptr %exp_mask, align 8
  %0 = load i64, ptr %x.addr, align 8
  %1 = load i64, ptr %exp_mask, align 8
  %and = and i64 %0, %1
  %cmp = icmp eq i64 %and, 0
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %2 = load i64, ptr %x.addr, align 8
  store i64 %2, ptr %retval, align 8
  br label %return

if.end:                                           ; preds = %entry
  %3 = load i64, ptr %x.addr, align 8
  %sub = sub i64 %3, 4503599627370496
  store i64 %sub, ptr %x.addr, align 8
  %4 = load i64, ptr %x.addr, align 8
  %5 = load i64, ptr %exp_mask, align 8
  %and1 = and i64 %4, %5
  %cmp2 = icmp eq i64 %and1, 0
  br i1 %cmp2, label %if.then3, label %if.end4

if.then3:                                         ; preds = %if.end
  store i64 0, ptr %retval, align 8
  br label %return

if.end4:                                          ; preds = %if.end
  %6 = load i64, ptr %x.addr, align 8
  store i64 %6, ptr %retval, align 8
  br label %return

return:                                           ; preds = %if.end4, %if.then3, %if.then
  %7 = load i64, ptr %retval, align 8
  ret i64 %7
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
