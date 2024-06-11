; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/c/0_alaw_to_s16_0.bc'
source_filename = "/home/javier/Galapagos/functions/alsa-lib/variants/c/0_alaw_to_s16_0.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @alaw_to_s16_v1(i8 noundef zeroext 97)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @alaw_to_s16_v1(i8 noundef zeroext %a_val) #0 {
entry:
  %a_val.addr = alloca i8, align 1
  %t = alloca i32, align 4
  %seg = alloca i32, align 4
  store i8 %a_val, ptr %a_val.addr, align 1
  %0 = load i8, ptr %a_val.addr, align 1
  %conv = zext i8 %0 to i32
  %xor = xor i32 %conv, 85
  %conv1 = trunc i32 %xor to i8
  store i8 %conv1, ptr %a_val.addr, align 1
  %1 = load i8, ptr %a_val.addr, align 1
  %conv2 = zext i8 %1 to i32
  %and = and i32 %conv2, 112
  %shr = ashr i32 %and, 4
  store i32 %shr, ptr %seg, align 4
  %2 = load i8, ptr %a_val.addr, align 1
  %conv3 = zext i8 %2 to i32
  %and4 = and i32 %conv3, 15
  %3 = load i32, ptr %seg, align 4
  %cmp = icmp eq i32 %3, 0
  br i1 %cmp, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  br label %cond.end

cond.false:                                       ; preds = %entry
  %4 = load i32, ptr %seg, align 4
  %add = add nsw i32 %4, 3
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ 4, %cond.true ], [ %add, %cond.false ]
  %shl = shl i32 %and4, %cond
  store i32 %shl, ptr %t, align 4
  %5 = load i32, ptr %t, align 4
  %add6 = add nsw i32 %5, 8
  store i32 %add6, ptr %t, align 4
  %6 = load i32, ptr %seg, align 4
  %tobool = icmp ne i32 %6, 0
  %7 = zext i1 %tobool to i64
  %cond7 = select i1 %tobool, i32 256, i32 0
  %8 = load i32, ptr %t, align 4
  %add8 = add nsw i32 %8, %cond7
  store i32 %add8, ptr %t, align 4
  %9 = load i8, ptr %a_val.addr, align 1
  %conv9 = zext i8 %9 to i32
  %and10 = and i32 %conv9, 128
  %tobool11 = icmp ne i32 %and10, 0
  br i1 %tobool11, label %cond.true12, label %cond.false13

cond.true12:                                      ; preds = %cond.end
  %10 = load i32, ptr %t, align 4
  br label %cond.end14

cond.false13:                                     ; preds = %cond.end
  %11 = load i32, ptr %t, align 4
  %sub = sub nsw i32 0, %11
  br label %cond.end14

cond.end14:                                       ; preds = %cond.false13, %cond.true12
  %cond15 = phi i32 [ %10, %cond.true12 ], [ %sub, %cond.false13 ]
  ret i32 %cond15
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
