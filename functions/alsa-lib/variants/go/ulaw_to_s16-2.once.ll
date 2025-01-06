; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/3_ulaw_to_s16.once.bc'
source_filename = "/home/javier/Galapagos/functions/alsa-lib/3_ulaw_to_s16.run.once.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @ulaw_to_s16(i8 noundef zeroext 97)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @ulaw_to_s16(i8 noundef zeroext %u_val) #0 {
entry:
  %xor.0 = xor i8 %u_val, -1
  %iand.1 = lshr i8 %xor.0, 4
  %shr.0 = and i8 %iand.1, 7
  %iand.0 = shl i8 %xor.0, 3
  %0 = or i8 %iand.0, -124
  %ior.0 = zext i8 %0 to i32
  %zext.2 = zext i8 %shr.0 to i32
  %shl.1 = shl nuw nsw i32 %ior.0, %zext.2
  %icmp.1.not = icmp slt i8 %u_val, 0
  %sub.0 = sub nsw i32 132, %shl.1
  %sub.1 = add nsw i32 %shl.1, -132
  %common.ret.op = select i1 %icmp.1.not, i32 %sub.1, i32 %sub.0
  ret i32 %common.ret.op
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
