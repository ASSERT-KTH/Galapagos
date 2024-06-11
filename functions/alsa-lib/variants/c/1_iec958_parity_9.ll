; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/c/1_iec958_parity_9.bc'
source_filename = "/home/javier/Galapagos/functions/alsa-lib/variants/c/1_iec958_parity_9.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @iec958_parity(i32 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @iec958_parity(i32 noundef %data) #0 {
entry:
  %data.addr = alloca i32, align 4
  %parity = alloca i32, align 4
  %bit = alloca i32, align 4
  store i32 %data, ptr %data.addr, align 4
  store i32 0, ptr %parity, align 4
  %0 = load i32, ptr %data.addr, align 4
  %shr = lshr i32 %0, 4
  store i32 %shr, ptr %data.addr, align 4
  store i32 4, ptr %bit, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %1 = load i32, ptr %bit, align 4
  %cmp = icmp sle i32 %1, 30
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %2 = load i32, ptr %data.addr, align 4
  %3 = load i32, ptr %bit, align 4
  %sub = sub nsw i32 %3, 4
  %shr1 = lshr i32 %2, %sub
  %and = and i32 %shr1, 1
  %4 = load i32, ptr %parity, align 4
  %xor = xor i32 %4, %and
  store i32 %xor, ptr %parity, align 4
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %5 = load i32, ptr %bit, align 4
  %inc = add nsw i32 %5, 1
  store i32 %inc, ptr %bit, align 4
  br label %for.cond, !llvm.loop !6

for.end:                                          ; preds = %for.cond
  %6 = load i32, ptr %parity, align 4
  %and2 = and i32 %6, 1
  ret i32 %and2
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
