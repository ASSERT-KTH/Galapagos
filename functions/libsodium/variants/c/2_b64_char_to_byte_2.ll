; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/c/2_b64_char_to_byte_2.bc'
source_filename = "/home/javier/Galapagos/functions/libsodium/variants/c/2_b64_char_to_byte_2.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @b64_char_to_byte(i32 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @b64_char_to_byte(i32 noundef %c) #0 {
entry:
  %retval = alloca i32, align 4
  %c.addr = alloca i32, align 4
  store i32 %c, ptr %c.addr, align 4
  %0 = load i32, ptr %c.addr, align 4
  switch i32 %0, label %sw.default [
    i32 43, label %sw.bb
    i32 47, label %sw.bb1
  ]

sw.bb:                                            ; preds = %entry
  store i32 62, ptr %retval, align 4
  br label %return

sw.bb1:                                           ; preds = %entry
  store i32 63, ptr %retval, align 4
  br label %return

sw.default:                                       ; preds = %entry
  %1 = load i32, ptr %c.addr, align 4
  %cmp = icmp sge i32 %1, 65
  br i1 %cmp, label %land.lhs.true, label %if.end

land.lhs.true:                                    ; preds = %sw.default
  %2 = load i32, ptr %c.addr, align 4
  %cmp2 = icmp sle i32 %2, 90
  br i1 %cmp2, label %if.then, label %if.end

if.then:                                          ; preds = %land.lhs.true
  %3 = load i32, ptr %c.addr, align 4
  %sub = sub nsw i32 %3, 65
  store i32 %sub, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %land.lhs.true, %sw.default
  %4 = load i32, ptr %c.addr, align 4
  %cmp3 = icmp sge i32 %4, 97
  br i1 %cmp3, label %land.lhs.true4, label %if.end8

land.lhs.true4:                                   ; preds = %if.end
  %5 = load i32, ptr %c.addr, align 4
  %cmp5 = icmp sle i32 %5, 122
  br i1 %cmp5, label %if.then6, label %if.end8

if.then6:                                         ; preds = %land.lhs.true4
  %6 = load i32, ptr %c.addr, align 4
  %sub7 = sub nsw i32 %6, 97
  %add = add nsw i32 %sub7, 26
  store i32 %add, ptr %retval, align 4
  br label %return

if.end8:                                          ; preds = %land.lhs.true4, %if.end
  %7 = load i32, ptr %c.addr, align 4
  %cmp9 = icmp sge i32 %7, 48
  br i1 %cmp9, label %land.lhs.true10, label %if.end15

land.lhs.true10:                                  ; preds = %if.end8
  %8 = load i32, ptr %c.addr, align 4
  %cmp11 = icmp sle i32 %8, 57
  br i1 %cmp11, label %if.then12, label %if.end15

if.then12:                                        ; preds = %land.lhs.true10
  %9 = load i32, ptr %c.addr, align 4
  %sub13 = sub nsw i32 %9, 48
  %add14 = add nsw i32 %sub13, 52
  store i32 %add14, ptr %retval, align 4
  br label %return

if.end15:                                         ; preds = %land.lhs.true10, %if.end8
  store i32 0, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end15, %if.then12, %if.then6, %if.then, %sw.bb1, %sw.bb
  %10 = load i32, ptr %retval, align 4
  ret i32 %10
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
