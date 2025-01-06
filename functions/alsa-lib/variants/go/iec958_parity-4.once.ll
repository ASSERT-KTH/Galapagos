; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/1_iec958_parity.once.bc'
source_filename = "/home/javier/Galapagos/functions/alsa-lib/1_iec958_parity.run.once.c"
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
  %shr.0 = lshr i32 %data, 4
  %shr.1 = lshr i32 %data, 5
  %iand.011 = xor i32 %shr.0, %shr.1
  %shr.1.1 = lshr i32 %data, 6
  %xor.0.112 = xor i32 %iand.011, %shr.1.1
  %shr.1.2 = lshr i32 %data, 7
  %xor.0.213 = xor i32 %xor.0.112, %shr.1.2
  %shr.1.3 = lshr i32 %data, 8
  %xor.0.314 = xor i32 %xor.0.213, %shr.1.3
  %shr.1.4 = lshr i32 %data, 9
  %xor.0.415 = xor i32 %xor.0.314, %shr.1.4
  %shr.1.5 = lshr i32 %data, 10
  %xor.0.516 = xor i32 %xor.0.415, %shr.1.5
  %shr.1.6 = lshr i32 %data, 11
  %xor.0.617 = xor i32 %xor.0.516, %shr.1.6
  %shr.1.7 = lshr i32 %data, 12
  %xor.0.718 = xor i32 %xor.0.617, %shr.1.7
  %shr.1.8 = lshr i32 %data, 13
  %xor.0.819 = xor i32 %xor.0.718, %shr.1.8
  %shr.1.9 = lshr i32 %data, 14
  %xor.0.920 = xor i32 %xor.0.819, %shr.1.9
  %shr.1.10 = lshr i32 %data, 15
  %xor.0.1021 = xor i32 %xor.0.920, %shr.1.10
  %shr.1.11 = lshr i32 %data, 16
  %xor.0.1122 = xor i32 %xor.0.1021, %shr.1.11
  %shr.1.12 = lshr i32 %data, 17
  %xor.0.1223 = xor i32 %xor.0.1122, %shr.1.12
  %shr.1.13 = lshr i32 %data, 18
  %xor.0.1324 = xor i32 %xor.0.1223, %shr.1.13
  %shr.1.14 = lshr i32 %data, 19
  %xor.0.1425 = xor i32 %xor.0.1324, %shr.1.14
  %shr.1.15 = lshr i32 %data, 20
  %xor.0.1526 = xor i32 %xor.0.1425, %shr.1.15
  %shr.1.16 = lshr i32 %data, 21
  %xor.0.1627 = xor i32 %xor.0.1526, %shr.1.16
  %shr.1.17 = lshr i32 %data, 22
  %xor.0.1728 = xor i32 %xor.0.1627, %shr.1.17
  %shr.1.18 = lshr i32 %data, 23
  %xor.0.1829 = xor i32 %xor.0.1728, %shr.1.18
  %shr.1.19 = lshr i32 %data, 24
  %xor.0.1930 = xor i32 %xor.0.1829, %shr.1.19
  %shr.1.20 = lshr i32 %data, 25
  %xor.0.2031 = xor i32 %xor.0.1930, %shr.1.20
  %shr.1.21 = lshr i32 %data, 26
  %xor.0.2132 = xor i32 %xor.0.2031, %shr.1.21
  %shr.1.22 = lshr i32 %data, 27
  %xor.0.2233 = xor i32 %xor.0.2132, %shr.1.22
  %shr.1.23 = lshr i32 %data, 28
  %xor.0.2334 = xor i32 %xor.0.2233, %shr.1.23
  %shr.1.24 = lshr i32 %data, 29
  %xor.0.2435 = xor i32 %xor.0.2334, %shr.1.24
  %shr.1.25 = lshr i32 %data, 30
  %xor.0.2536 = xor i32 %xor.0.2435, %shr.1.25
  %xor.0.26 = and i32 %xor.0.2536, 1
  ret i32 %xor.0.26
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
