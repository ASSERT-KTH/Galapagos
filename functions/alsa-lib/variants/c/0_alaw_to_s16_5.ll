; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/c/0_alaw_to_s16_5.bc'
source_filename = "/home/javier/Galapagos/functions/alsa-lib/variants/c/0_alaw_to_s16_5.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @alaw_to_s16_v6(i8 noundef zeroext 97)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @alaw_to_s16_v6(i8 noundef zeroext %a_val) #0 {
entry:
  %a_val.addr = alloca i8, align 1
  %t = alloca i32, align 4
  %seg = alloca i32, align 4
  store i8 %a_val, ptr %a_val.addr, align 1
  %0 = load i8, ptr %a_val.addr, align 1
  %conv = zext i8 %0 to i32
  %xor = xor i32 %conv, 85
  store i32 %xor, ptr %t, align 4
  %1 = load i32, ptr %t, align 4
  %and = and i32 %1, 15
  %2 = load i32, ptr %t, align 4
  %and1 = and i32 %2, 112
  %shl = shl i32 %and1, 4
  %or = or i32 %and, %shl
  %or2 = or i32 %or, 128
  store i32 %or2, ptr %t, align 4
  %3 = load i8, ptr %a_val.addr, align 1
  %conv3 = zext i8 %3 to i32
  %and4 = and i32 %conv3, 112
  %shr = ashr i32 %and4, 4
  store i32 %shr, ptr %seg, align 4
  %4 = load i32, ptr %seg, align 4
  %tobool = icmp ne i32 %4, 0
  br i1 %tobool, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %5 = load i32, ptr %t, align 4
  %add = add nsw i32 %5, 256
  store i32 %add, ptr %t, align 4
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %6 = load i32, ptr %seg, align 4
  %tobool5 = icmp ne i32 %6, 0
  br i1 %tobool5, label %cond.true, label %cond.false

cond.true:                                        ; preds = %if.end
  %7 = load i32, ptr %seg, align 4
  br label %cond.end

cond.false:                                       ; preds = %if.end
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %7, %cond.true ], [ 0, %cond.false ]
  %8 = load i32, ptr %t, align 4
  %shl6 = shl i32 %8, %cond
  store i32 %shl6, ptr %t, align 4
  %9 = load i8, ptr %a_val.addr, align 1
  %conv7 = zext i8 %9 to i32
  %and8 = and i32 %conv7, 128
  %tobool9 = icmp ne i32 %and8, 0
  br i1 %tobool9, label %cond.true10, label %cond.false11

cond.true10:                                      ; preds = %cond.end
  %10 = load i32, ptr %t, align 4
  br label %cond.end12

cond.false11:                                     ; preds = %cond.end
  %11 = load i32, ptr %t, align 4
  %sub = sub nsw i32 0, %11
  br label %cond.end12

cond.end12:                                       ; preds = %cond.false11, %cond.true10
  %cond13 = phi i32 [ %10, %cond.true10 ], [ %sub, %cond.false11 ]
  ret i32 %cond13
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
