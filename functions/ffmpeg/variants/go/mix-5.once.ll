; ModuleID = '/home/javier/Galapagos/functions/ffmpeg/1_mix.once.bc'
source_filename = "/home/javier/Galapagos/functions/ffmpeg/1_mix.run.once.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @mix(i32 noundef 0, i32 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @mix(i32 noundef %c0, i32 noundef %c1) #0 {
entry:
  %iand.0 = shl i32 %c0, 1
  %mul.0 = and i32 %iand.0, 62
  %iand.1 = and i32 %c1, 31
  %add.0 = add nuw nsw i32 %mul.0, %iand.1
  %0 = lshr i32 %c0, 4
  %1 = and i32 %0, 62
  %iand.3 = lshr i32 %c1, 5
  %2 = and i32 %iand.3, 31
  %add.1 = add nuw nsw i32 %2, %1
  %3 = ashr i32 %c0, 9
  %mul.2 = and i32 %3, -2
  %shr.3 = ashr i32 %c1, 10
  %add.2 = add nsw i32 %mul.2, %shr.3
  %div.0 = sdiv i32 %add.2, 3
  %mul.3 = shl i32 %div.0, 10
  %div.1.lhs.trunc = trunc i32 %add.1 to i8
  %div.19 = udiv i8 %div.1.lhs.trunc, 3
  %div.1.zext = zext i8 %div.19 to i32
  %mul.4 = shl nuw nsw i32 %div.1.zext, 5
  %div.2.lhs.trunc = trunc i32 %add.0 to i8
  %div.210 = udiv i8 %div.2.lhs.trunc, 3
  %div.2.zext = zext i8 %div.210 to i32
  %add.3 = or i32 %mul.3, %div.2.zext
  %add.4 = add i32 %add.3, %mul.4
  ret i32 %add.4
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
