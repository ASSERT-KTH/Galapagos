; ModuleID = '/home/javier/Galapagos/functions/liboqs/1_fpr_lt.once.bc'
source_filename = "/home/javier/Galapagos/functions/liboqs/1_fpr_lt.run.once.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @fpr_lt(i64 noundef 0, i64 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @fpr_lt(i64 noundef %x, i64 noundef %y) #0 {
entry:
  %icmp.0 = icmp slt i64 %x, 0
  %x.lobit = lshr i64 %x, 63
  %0 = trunc i64 %x.lobit to i8
  %y.lobit24 = lshr i64 %y, 63
  %1 = trunc i64 %y.lobit24 to i8
  %tmpv.0.0 = select i1 %icmp.0, i8 %1, i8 %0
  %trunc.5.not = icmp eq i8 %tmpv.0.0, 0
  br i1 %trunc.5.not, label %else.1, label %then.1

common.ret:                                       ; preds = %else.1, %then.1
  %common.ret.op.in.in = phi i64 [ %sub.0, %then.1 ], [ %spec.select, %else.1 ]
  %common.ret.op.in = lshr i64 %common.ret.op.in.in, 63
  %common.ret.op = trunc i64 %common.ret.op.in to i32
  ret i32 %common.ret.op

then.1:                                           ; preds = %entry
  %sub.0 = sub i64 %y, %x
  br label %common.ret

else.1:                                           ; preds = %entry
  %tmpv.2.0 = select i1 %icmp.0, i8 %0, i8 %1
  %trunc.4.not = icmp eq i8 %tmpv.2.0, 0
  %sub.1 = select i1 %trunc.4.not, i64 %y, i64 0
  %spec.select = sub i64 %x, %sub.1
  br label %common.ret
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
