; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/c/1_b64_byte_to_urlsafe_char_3.bc'
source_filename = "/home/javier/Galapagos/functions/libsodium/variants/c/1_b64_byte_to_urlsafe_char_3.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @b64_byte_to_urlsafe_char(i32 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @b64_byte_to_urlsafe_char(i32 noundef %x) #0 {
entry:
  %retval = alloca i32, align 4
  %x.addr = alloca i32, align 4
  store i32 %x, ptr %x.addr, align 4
  %0 = load i32, ptr %x.addr, align 4
  %cmp = icmp uge i32 %0, 0
  br i1 %cmp, label %land.lhs.true, label %if.end

land.lhs.true:                                    ; preds = %entry
  %1 = load i32, ptr %x.addr, align 4
  %cmp1 = icmp ule i32 %1, 25
  br i1 %cmp1, label %if.then, label %if.end

if.then:                                          ; preds = %land.lhs.true
  %2 = load i32, ptr %x.addr, align 4
  %add = add i32 %2, 65
  store i32 %add, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %land.lhs.true, %entry
  %3 = load i32, ptr %x.addr, align 4
  %cmp2 = icmp uge i32 %3, 26
  br i1 %cmp2, label %land.lhs.true3, label %if.end7

land.lhs.true3:                                   ; preds = %if.end
  %4 = load i32, ptr %x.addr, align 4
  %cmp4 = icmp ule i32 %4, 51
  br i1 %cmp4, label %if.then5, label %if.end7

if.then5:                                         ; preds = %land.lhs.true3
  %5 = load i32, ptr %x.addr, align 4
  %sub = sub i32 %5, 26
  %add6 = add i32 %sub, 97
  store i32 %add6, ptr %retval, align 4
  br label %return

if.end7:                                          ; preds = %land.lhs.true3, %if.end
  %6 = load i32, ptr %x.addr, align 4
  %cmp8 = icmp uge i32 %6, 52
  br i1 %cmp8, label %land.lhs.true9, label %if.end14

land.lhs.true9:                                   ; preds = %if.end7
  %7 = load i32, ptr %x.addr, align 4
  %cmp10 = icmp ule i32 %7, 61
  br i1 %cmp10, label %if.then11, label %if.end14

if.then11:                                        ; preds = %land.lhs.true9
  %8 = load i32, ptr %x.addr, align 4
  %sub12 = sub i32 %8, 52
  %add13 = add i32 %sub12, 48
  store i32 %add13, ptr %retval, align 4
  br label %return

if.end14:                                         ; preds = %land.lhs.true9, %if.end7
  %9 = load i32, ptr %x.addr, align 4
  %cmp15 = icmp eq i32 %9, 62
  br i1 %cmp15, label %if.then16, label %if.end17

if.then16:                                        ; preds = %if.end14
  store i32 45, ptr %retval, align 4
  br label %return

if.end17:                                         ; preds = %if.end14
  %10 = load i32, ptr %x.addr, align 4
  %cmp18 = icmp eq i32 %10, 63
  br i1 %cmp18, label %if.then19, label %if.end20

if.then19:                                        ; preds = %if.end17
  store i32 95, ptr %retval, align 4
  br label %return

if.end20:                                         ; preds = %if.end17
  store i32 -1, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end20, %if.then19, %if.then16, %if.then11, %if.then5, %if.then
  %11 = load i32, ptr %retval, align 4
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
