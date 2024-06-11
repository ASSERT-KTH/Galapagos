; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/c/3_b64_urlsafe_char_to_byte_9.bc'
source_filename = "/home/javier/Galapagos/functions/libsodium/variants/c/3_b64_urlsafe_char_to_byte_9.c"
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
  %retval = alloca i32, align 4
  %c.addr = alloca i32, align 4
  store i32 %c, ptr %c.addr, align 4
  %0 = load i32, ptr %c.addr, align 4
  %cmp = icmp eq i32 %0, 43
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i32 62, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  %1 = load i32, ptr %c.addr, align 4
  %cmp1 = icmp eq i32 %1, 47
  br i1 %cmp1, label %if.then2, label %if.end3

if.then2:                                         ; preds = %if.end
  store i32 63, ptr %retval, align 4
  br label %return

if.end3:                                          ; preds = %if.end
  %2 = load i32, ptr %c.addr, align 4
  %cmp4 = icmp sge i32 %2, 65
  br i1 %cmp4, label %land.lhs.true, label %if.end7

land.lhs.true:                                    ; preds = %if.end3
  %3 = load i32, ptr %c.addr, align 4
  %cmp5 = icmp sle i32 %3, 90
  br i1 %cmp5, label %if.then6, label %if.end7

if.then6:                                         ; preds = %land.lhs.true
  %4 = load i32, ptr %c.addr, align 4
  %sub = sub nsw i32 %4, 65
  store i32 %sub, ptr %retval, align 4
  br label %return

if.end7:                                          ; preds = %land.lhs.true, %if.end3
  %5 = load i32, ptr %c.addr, align 4
  %cmp8 = icmp sge i32 %5, 97
  br i1 %cmp8, label %land.lhs.true9, label %if.end13

land.lhs.true9:                                   ; preds = %if.end7
  %6 = load i32, ptr %c.addr, align 4
  %cmp10 = icmp sle i32 %6, 122
  br i1 %cmp10, label %if.then11, label %if.end13

if.then11:                                        ; preds = %land.lhs.true9
  %7 = load i32, ptr %c.addr, align 4
  %sub12 = sub nsw i32 %7, 97
  %add = add nsw i32 %sub12, 26
  store i32 %add, ptr %retval, align 4
  br label %return

if.end13:                                         ; preds = %land.lhs.true9, %if.end7
  %8 = load i32, ptr %c.addr, align 4
  %cmp14 = icmp sge i32 %8, 48
  br i1 %cmp14, label %land.lhs.true15, label %if.end20

land.lhs.true15:                                  ; preds = %if.end13
  %9 = load i32, ptr %c.addr, align 4
  %cmp16 = icmp sle i32 %9, 57
  br i1 %cmp16, label %if.then17, label %if.end20

if.then17:                                        ; preds = %land.lhs.true15
  %10 = load i32, ptr %c.addr, align 4
  %sub18 = sub nsw i32 %10, 48
  %add19 = add nsw i32 %sub18, 52
  store i32 %add19, ptr %retval, align 4
  br label %return

if.end20:                                         ; preds = %land.lhs.true15, %if.end13
  %11 = load i32, ptr %c.addr, align 4
  %cmp21 = icmp eq i32 %11, 45
  br i1 %cmp21, label %if.then22, label %if.end23

if.then22:                                        ; preds = %if.end20
  store i32 62, ptr %retval, align 4
  br label %return

if.end23:                                         ; preds = %if.end20
  %12 = load i32, ptr %c.addr, align 4
  %cmp24 = icmp eq i32 %12, 95
  br i1 %cmp24, label %if.then25, label %if.end26

if.then25:                                        ; preds = %if.end23
  store i32 63, ptr %retval, align 4
  br label %return

if.end26:                                         ; preds = %if.end23
  store i32 0, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end26, %if.then25, %if.then22, %if.then17, %if.then11, %if.then6, %if.then2, %if.then
  %13 = load i32, ptr %retval, align 4
  ret i32 %13
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
