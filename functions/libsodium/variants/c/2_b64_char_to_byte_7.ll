; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/c/2_b64_char_to_byte_7.bc'
source_filename = "/home/javier/Galapagos/functions/libsodium/variants/c/2_b64_char_to_byte_7.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@b64_char_to_byte.lookup = internal constant [48 x i32] [i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 62, i32 0, i32 0, i32 0, i32 63], align 16

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
  %cmp = icmp sle i32 65, %0
  br i1 %cmp, label %land.lhs.true, label %if.end

land.lhs.true:                                    ; preds = %entry
  %1 = load i32, ptr %c.addr, align 4
  %cmp1 = icmp sle i32 %1, 90
  br i1 %cmp1, label %if.then, label %if.end

if.then:                                          ; preds = %land.lhs.true
  %2 = load i32, ptr %c.addr, align 4
  %sub = sub nsw i32 %2, 65
  store i32 %sub, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %land.lhs.true, %entry
  %3 = load i32, ptr %c.addr, align 4
  %cmp2 = icmp sle i32 97, %3
  br i1 %cmp2, label %land.lhs.true3, label %if.end7

land.lhs.true3:                                   ; preds = %if.end
  %4 = load i32, ptr %c.addr, align 4
  %cmp4 = icmp sle i32 %4, 122
  br i1 %cmp4, label %if.then5, label %if.end7

if.then5:                                         ; preds = %land.lhs.true3
  %5 = load i32, ptr %c.addr, align 4
  %sub6 = sub nsw i32 %5, 97
  %add = add nsw i32 %sub6, 26
  store i32 %add, ptr %retval, align 4
  br label %return

if.end7:                                          ; preds = %land.lhs.true3, %if.end
  %6 = load i32, ptr %c.addr, align 4
  %cmp8 = icmp sle i32 48, %6
  br i1 %cmp8, label %land.lhs.true9, label %if.end14

land.lhs.true9:                                   ; preds = %if.end7
  %7 = load i32, ptr %c.addr, align 4
  %cmp10 = icmp sle i32 %7, 57
  br i1 %cmp10, label %if.then11, label %if.end14

if.then11:                                        ; preds = %land.lhs.true9
  %8 = load i32, ptr %c.addr, align 4
  %sub12 = sub nsw i32 %8, 48
  %add13 = add nsw i32 %sub12, 52
  store i32 %add13, ptr %retval, align 4
  br label %return

if.end14:                                         ; preds = %land.lhs.true9, %if.end7
  %9 = load i32, ptr %c.addr, align 4
  %cmp15 = icmp eq i32 %9, 43
  br i1 %cmp15, label %if.then17, label %lor.lhs.false

lor.lhs.false:                                    ; preds = %if.end14
  %10 = load i32, ptr %c.addr, align 4
  %cmp16 = icmp eq i32 %10, 47
  br i1 %cmp16, label %if.then17, label %if.end18

if.then17:                                        ; preds = %lor.lhs.false, %if.end14
  %11 = load i32, ptr %c.addr, align 4
  %idxprom = sext i32 %11 to i64
  %arrayidx = getelementptr inbounds [48 x i32], ptr @b64_char_to_byte.lookup, i64 0, i64 %idxprom
  %12 = load i32, ptr %arrayidx, align 4
  store i32 %12, ptr %retval, align 4
  br label %return

if.end18:                                         ; preds = %lor.lhs.false
  store i32 0, ptr %retval, align 4
  br label %return

return:                                           ; preds = %if.end18, %if.then17, %if.then11, %if.then5, %if.then
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