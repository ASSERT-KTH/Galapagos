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
  %iand.0 = and i32 %shr.0, 1
  %shr.1 = lshr i32 %data, 5
  %iand.0.1 = and i32 %shr.1, 1
  %narrow = add nuw nsw i32 %iand.0, %iand.0.1
  %shr.1.1 = lshr i32 %data, 6
  %iand.0.2 = and i32 %shr.1.1, 1
  %narrow11 = add nuw nsw i32 %narrow, %iand.0.2
  %shr.1.2 = lshr i32 %data, 7
  %iand.0.3 = and i32 %shr.1.2, 1
  %narrow12 = add nuw nsw i32 %narrow11, %iand.0.3
  %shr.1.3 = lshr i32 %data, 8
  %iand.0.4 = and i32 %shr.1.3, 1
  %narrow13 = add nuw nsw i32 %narrow12, %iand.0.4
  %shr.1.4 = lshr i32 %data, 9
  %iand.0.5 = and i32 %shr.1.4, 1
  %narrow14 = add nuw nsw i32 %narrow13, %iand.0.5
  %shr.1.5 = lshr i32 %data, 10
  %iand.0.6 = and i32 %shr.1.5, 1
  %narrow15 = add nuw nsw i32 %narrow14, %iand.0.6
  %shr.1.6 = lshr i32 %data, 11
  %0 = and i32 %shr.1.6, 1
  %parity.1.7 = add i32 %0, %narrow15
  %shr.1.7 = lshr i32 %data, 12
  %1 = and i32 %shr.1.7, 1
  %parity.1.8 = add i32 %parity.1.7, %1
  %shr.1.8 = lshr i32 %data, 13
  %2 = and i32 %shr.1.8, 1
  %parity.1.9 = add i32 %parity.1.8, %2
  %shr.1.9 = lshr i32 %data, 14
  %3 = and i32 %shr.1.9, 1
  %parity.1.10 = add i32 %parity.1.9, %3
  %shr.1.10 = lshr i32 %data, 15
  %4 = and i32 %shr.1.10, 1
  %parity.1.11 = add i32 %parity.1.10, %4
  %shr.1.11 = lshr i32 %data, 16
  %5 = and i32 %shr.1.11, 1
  %parity.1.12 = add i32 %parity.1.11, %5
  %shr.1.12 = lshr i32 %data, 17
  %6 = and i32 %shr.1.12, 1
  %parity.1.13 = add i32 %parity.1.12, %6
  %shr.1.13 = lshr i32 %data, 18
  %7 = and i32 %shr.1.13, 1
  %parity.1.14 = add i32 %parity.1.13, %7
  %shr.1.14 = lshr i32 %data, 19
  %8 = and i32 %shr.1.14, 1
  %parity.1.15 = add i32 %parity.1.14, %8
  %shr.1.15 = lshr i32 %data, 20
  %9 = and i32 %shr.1.15, 1
  %parity.1.16 = add i32 %parity.1.15, %9
  %shr.1.16 = lshr i32 %data, 21
  %10 = and i32 %shr.1.16, 1
  %parity.1.17 = add i32 %parity.1.16, %10
  %shr.1.17 = lshr i32 %data, 22
  %11 = and i32 %shr.1.17, 1
  %parity.1.18 = add i32 %parity.1.17, %11
  %shr.1.18 = lshr i32 %data, 23
  %12 = and i32 %shr.1.18, 1
  %parity.1.19 = add i32 %parity.1.18, %12
  %shr.1.19 = lshr i32 %data, 24
  %13 = and i32 %shr.1.19, 1
  %parity.1.20 = add i32 %parity.1.19, %13
  %shr.1.20 = lshr i32 %data, 25
  %14 = and i32 %shr.1.20, 1
  %parity.1.21 = add i32 %parity.1.20, %14
  %shr.1.21 = lshr i32 %data, 26
  %15 = and i32 %shr.1.21, 1
  %parity.1.22 = add i32 %parity.1.21, %15
  %shr.1.22 = lshr i32 %data, 27
  %parity.1.23 = add i32 %parity.1.22, %shr.1.22
  %shr.1.23 = lshr i32 %data, 28
  %parity.1.24 = add i32 %parity.1.23, %shr.1.23
  %shr.1.24 = lshr i32 %data, 29
  %parity.1.25 = add i32 %parity.1.24, %shr.1.24
  %shr.1.25 = lshr i32 %data, 30
  %parity.1.26 = add i32 %parity.1.25, %shr.1.25
  %mod.01617 = and i32 %parity.1.26, 1
  ret i32 %mod.01617
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
