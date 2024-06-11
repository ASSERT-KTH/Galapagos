; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/c/3_b64_urlsafe_char_to_byte_7.bc'
source_filename = "/home/javier/Galapagos/functions/libsodium/variants/c/3_b64_urlsafe_char_to_byte_7.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @b64_urlsafe_char_to_byte(i32 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @b64_urlsafe_char_to_byte(i32 noundef %c) #0 {
entry:
  %c.addr = alloca i32, align 4
  %x = alloca i32, align 4
  store i32 %c, ptr %c.addr, align 4
  store i32 0, ptr %x, align 4
  %0 = load i32, ptr %c.addr, align 4
  %cmp = icmp sge i32 %0, 65
  br i1 %cmp, label %land.lhs.true, label %if.else

land.lhs.true:                                    ; preds = %entry
  %1 = load i32, ptr %c.addr, align 4
  %cmp1 = icmp sle i32 %1, 90
  br i1 %cmp1, label %if.then, label %if.else

if.then:                                          ; preds = %land.lhs.true
  %2 = load i32, ptr %c.addr, align 4
  %sub = sub nsw i32 %2, 65
  store i32 %sub, ptr %x, align 4
  br label %if.end23

if.else:                                          ; preds = %land.lhs.true, %entry
  %3 = load i32, ptr %c.addr, align 4
  %cmp2 = icmp sge i32 %3, 97
  br i1 %cmp2, label %land.lhs.true3, label %if.else7

land.lhs.true3:                                   ; preds = %if.else
  %4 = load i32, ptr %c.addr, align 4
  %cmp4 = icmp sle i32 %4, 122
  br i1 %cmp4, label %if.then5, label %if.else7

if.then5:                                         ; preds = %land.lhs.true3
  %5 = load i32, ptr %c.addr, align 4
  %sub6 = sub nsw i32 %5, 97
  %add = add nsw i32 %sub6, 26
  store i32 %add, ptr %x, align 4
  br label %if.end22

if.else7:                                         ; preds = %land.lhs.true3, %if.else
  %6 = load i32, ptr %c.addr, align 4
  %cmp8 = icmp sge i32 %6, 48
  br i1 %cmp8, label %land.lhs.true9, label %if.else14

land.lhs.true9:                                   ; preds = %if.else7
  %7 = load i32, ptr %c.addr, align 4
  %cmp10 = icmp sle i32 %7, 57
  br i1 %cmp10, label %if.then11, label %if.else14

if.then11:                                        ; preds = %land.lhs.true9
  %8 = load i32, ptr %c.addr, align 4
  %sub12 = sub nsw i32 %8, 48
  %add13 = add nsw i32 %sub12, 52
  store i32 %add13, ptr %x, align 4
  br label %if.end21

if.else14:                                        ; preds = %land.lhs.true9, %if.else7
  %9 = load i32, ptr %c.addr, align 4
  %cmp15 = icmp eq i32 %9, 45
  br i1 %cmp15, label %if.then16, label %if.else17

if.then16:                                        ; preds = %if.else14
  store i32 62, ptr %x, align 4
  br label %if.end20

if.else17:                                        ; preds = %if.else14
  %10 = load i32, ptr %c.addr, align 4
  %cmp18 = icmp eq i32 %10, 95
  br i1 %cmp18, label %if.then19, label %if.end

if.then19:                                        ; preds = %if.else17
  store i32 63, ptr %x, align 4
  br label %if.end

if.end:                                           ; preds = %if.then19, %if.else17
  br label %if.end20

if.end20:                                         ; preds = %if.end, %if.then16
  br label %if.end21

if.end21:                                         ; preds = %if.end20, %if.then11
  br label %if.end22

if.end22:                                         ; preds = %if.end21, %if.then5
  br label %if.end23

if.end23:                                         ; preds = %if.end22, %if.then
  %11 = load i32, ptr %x, align 4
  ret i32 %11
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
