; ModuleID = '../functions/openssl/2_BitInterleave.once.bc'
source_filename = "/home/javier/Galapagos/functions/openssl/2_BitInterleave.run.once.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i64 @BitInterleave(i64 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @BitInterleave(i64 noundef %Ai) #0 {
entry:
  %trunc.0 = trunc i64 %Ai to i32
  %shr.0 = lshr i64 %Ai, 32
  %trunc.1 = trunc i64 %shr.0 to i32
  %shl.0 = shl i32 %trunc.0, 8
  %ior.0 = or i32 %shl.0, %trunc.0
  %iand.0 = and i32 %ior.0, 16711935
  %shl.1 = shl nuw nsw i32 %iand.0, 4
  %ior.1 = or i32 %shl.1, %iand.0
  %iand.1 = and i32 %ior.1, 252645135
  %shl.2 = shl nuw nsw i32 %iand.1, 2
  %ior.2 = or i32 %shl.2, %iand.1
  %iand.2 = and i32 %ior.2, 858993459
  %shl.3 = shl nuw nsw i32 %iand.2, 1
  %ior.3 = or i32 %shl.3, %iand.2
  %iand.3 = and i32 %ior.3, 1431655765
  %shl.4 = shl i32 %trunc.1, 8
  %ior.4 = or i32 %shl.4, %trunc.1
  %iand.4 = and i32 %ior.4, 16711935
  %shl.5 = shl nuw nsw i32 %iand.4, 4
  %ior.5 = or i32 %shl.5, %iand.4
  %iand.5 = and i32 %ior.5, 252645135
  %shl.6 = shl nuw nsw i32 %iand.5, 2
  %ior.6 = or i32 %shl.6, %iand.5
  %iand.6 = and i32 %ior.6, 858993459
  %shl.7 = shl nuw nsw i32 %iand.6, 1
  %ior.7 = or i32 %shl.7, %iand.6
  %iand.7 = and i32 %ior.7, 1431655765
  %zext.0 = zext i32 %iand.7 to i64
  %zext.1 = zext i32 %iand.3 to i64
  %shl.8 = shl nuw nsw i64 %zext.0, 32
  %ior.8 = or i64 %shl.8, %zext.1
  ret i64 %ior.8
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
