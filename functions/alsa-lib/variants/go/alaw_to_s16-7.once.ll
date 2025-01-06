; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/0_alaw_to_s16.once.bc'
source_filename = "/home/javier/Galapagos/functions/alsa-lib/0_alaw_to_s16.run.once.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @alaw_to_s16(i8 noundef zeroext 97)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @alaw_to_s16(i8 noundef zeroext %aVal) #0 {
entry:
  %xor.0 = and i8 %aVal, 127
  %iand.0 = xor i8 %xor.0, 85
  %zext.0 = zext i8 %iand.0 to i32
  %icmp.6 = icmp ult i8 %iand.0, 16
  br i1 %icmp.6, label %then.0, label %else.0

then.0:                                           ; preds = %entry
  %mul.0 = shl nuw nsw i32 %zext.0, 4
  %add.0 = or i32 %mul.0, 8
  br label %fallthrough.0

fallthrough.0:                                    ; preds = %else.0, %then.0
  %t.0 = phi i32 [ %add.0, %then.0 ], [ %shl.0, %else.0 ]
  %icmp.7.not = icmp sgt i8 %aVal, -1
  %sub.2 = sub i32 0, %t.0
  %common.ret.op = select i1 %icmp.7.not, i32 %sub.2, i32 %t.0
  ret i32 %common.ret.op

else.0:                                           ; preds = %entry
  %div.0 = lshr i32 %zext.0, 4
  %mod.0 = shl nuw nsw i32 %zext.0, 4
  %mul.1 = and i32 %mod.0, 240
  %add.1 = or i32 %mul.1, 264
  %sub.1 = add nsw i32 %div.0, -1
  %shl.0 = shl i32 %add.1, %sub.1
  br label %fallthrough.0
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
