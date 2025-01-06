; ModuleID = '/home/javier/Galapagos/functions/libgcrypt/1_ctz.once.bc'
source_filename = "/home/javier/Galapagos/functions/libgcrypt/1_ctz.run.once.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @ctz(i64 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @ctz(i64 noundef %in) #0 {
entry:
  br label %then.3

else.2:                                           ; preds = %then.3
  %add.1 = or i64 %i.010, 1
  %0 = shl nuw i64 1, %add.1
  %1 = and i64 %0, %in
  %icmp.2.not.1 = icmp eq i64 %1, 0
  br i1 %icmp.2.not.1, label %else.2.1, label %label.2.split.loop.exit12

else.2.1:                                         ; preds = %else.2
  %add.1.1 = or i64 %i.010, 2
  %2 = shl nuw i64 1, %add.1.1
  %3 = and i64 %2, %in
  %icmp.2.not.2 = icmp eq i64 %3, 0
  br i1 %icmp.2.not.2, label %else.2.2, label %label.2.split.loop.exit12

else.2.2:                                         ; preds = %else.2.1
  %add.1.2 = or i64 %i.010, 3
  %4 = shl nuw i64 1, %add.1.2
  %5 = and i64 %4, %in
  %icmp.2.not.3 = icmp eq i64 %5, 0
  br i1 %icmp.2.not.3, label %else.2.3, label %label.2.split.loop.exit12

else.2.3:                                         ; preds = %else.2.2
  %add.1.3 = add nuw nsw i64 %i.010, 4
  %exitcond.not.3 = icmp eq i64 %add.1.3, 64
  br i1 %exitcond.not.3, label %label.2, label %then.3

label.2.split.loop.exit12:                        ; preds = %then.3, %else.2.2, %else.2.1, %else.2
  %i.010.lcssa = phi i64 [ %i.010, %then.3 ], [ %add.1, %else.2 ], [ %add.1.1, %else.2.1 ], [ %add.1.2, %else.2.2 ]
  %indvars11.le = trunc i64 %i.010.lcssa to i32
  br label %label.2

label.2:                                          ; preds = %label.2.split.loop.exit12, %else.2.3
  %r.0.lcssa = phi i32 [ %indvars11.le, %label.2.split.loop.exit12 ], [ 64, %else.2.3 ]
  ret i32 %r.0.lcssa

then.3:                                           ; preds = %else.2.3, %entry
  %i.010 = phi i64 [ 0, %entry ], [ %add.1.3, %else.2.3 ]
  %6 = shl nuw i64 1, %i.010
  %7 = and i64 %6, %in
  %icmp.2.not = icmp eq i64 %7, 0
  br i1 %icmp.2.not, label %else.2, label %label.2.split.loop.exit12
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
