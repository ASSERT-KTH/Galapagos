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
  %iand.07 = and i64 %in, 1
  %icmp.08 = icmp eq i64 %iand.07, 0
  br i1 %icmp.08, label %then.1, label %else.1

then.1:                                           ; preds = %then.1, %entry
  %r.010 = phi i32 [ %add.0, %then.1 ], [ 0, %entry ]
  %in.addr.09 = phi i64 [ %shr.0, %then.1 ], [ %in, %entry ]
  %shr.0 = lshr i64 %in.addr.09, 1
  %add.0 = add nuw nsw i32 %r.010, 1
  %0 = and i64 %in.addr.09, 2
  %icmp.0 = icmp eq i64 %0, 0
  %icmp.1 = icmp ult i32 %r.010, 63
  %spec.select = select i1 %icmp.0, i1 %icmp.1, i1 false
  br i1 %spec.select, label %then.1, label %else.1

else.1:                                           ; preds = %then.1, %entry
  %r.0.lcssa = phi i32 [ 0, %entry ], [ %add.0, %then.1 ]
  ret i32 %r.0.lcssa
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
