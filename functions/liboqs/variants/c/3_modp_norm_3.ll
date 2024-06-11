; ModuleID = '/home/javier/Galapagos/functions/liboqs/variants/c/3_modp_norm_3.bc'
source_filename = "/home/javier/Galapagos/functions/liboqs/variants/c/3_modp_norm_3.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @modp_norm(i32 noundef %x, i32 noundef %p) #0 {
entry:
  %x.addr = alloca i32, align 4
  %p.addr = alloca i32, align 4
  store i32 %x, ptr %x.addr, align 4
  store i32 %p, ptr %p.addr, align 4
  %0 = load i32, ptr %x.addr, align 4
  %1 = load i32, ptr %x.addr, align 4
  %2 = load i32, ptr %p.addr, align 4
  %add = add i32 %2, 1
  %div = udiv i32 %add, 2
  %cmp = icmp uge i32 %1, %div
  br i1 %cmp, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  %3 = load i32, ptr %p.addr, align 4
  br label %cond.end

cond.false:                                       ; preds = %entry
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %3, %cond.true ], [ 0, %cond.false ]
  %sub = sub i32 %0, %cond
  ret i32 %sub
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @modp_norm(i32 noundef 0, i32 noundef 0)
  ret i32 0
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
