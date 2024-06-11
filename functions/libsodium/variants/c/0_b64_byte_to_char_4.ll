; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/c/0_b64_byte_to_char_4.bc'
source_filename = "/home/javier/Galapagos/functions/libsodium/variants/c/0_b64_byte_to_char_4.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @b64_byte_to_char(i32 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @b64_byte_to_char(i32 noundef %x) #0 {
entry:
  %retval = alloca i32, align 4
  %x.addr = alloca i32, align 4
  store i32 %x, ptr %x.addr, align 4
  %0 = load i32, ptr %x.addr, align 4
  switch i32 %0, label %sw.default [
    i32 62, label %sw.bb
    i32 63, label %sw.bb1
  ]

sw.bb:                                            ; preds = %entry
  store i32 43, ptr %retval, align 4
  br label %return

sw.bb1:                                           ; preds = %entry
  store i32 47, ptr %retval, align 4
  br label %return

sw.default:                                       ; preds = %entry
  %1 = load i32, ptr %x.addr, align 4
  %2 = load i32, ptr %x.addr, align 4
  %cmp = icmp ult i32 %2, 26
  br i1 %cmp, label %cond.true, label %cond.false

cond.true:                                        ; preds = %sw.default
  br label %cond.end

cond.false:                                       ; preds = %sw.default
  %3 = load i32, ptr %x.addr, align 4
  %cmp2 = icmp ult i32 %3, 52
  %4 = zext i1 %cmp2 to i64
  %cond = select i1 %cmp2, i32 71, i32 -4
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond3 = phi i32 [ 65, %cond.true ], [ %cond, %cond.false ]
  %add = add i32 %1, %cond3
  store i32 %add, ptr %retval, align 4
  br label %return

return:                                           ; preds = %cond.end, %sw.bb1, %sw.bb
  %5 = load i32, ptr %retval, align 4
  ret i32 %5
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
