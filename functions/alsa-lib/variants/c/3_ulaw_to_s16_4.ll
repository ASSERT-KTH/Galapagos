; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/c/3_ulaw_to_s16_4.bc'
source_filename = "/home/javier/Galapagos/functions/alsa-lib/variants/c/3_ulaw_to_s16_4.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @ulaw_to_s16(i8 noundef zeroext 97)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @ulaw_to_s16(i8 noundef zeroext %u_val) #0 {
entry:
  %u_val.addr = alloca i8, align 1
  %temp = alloca i32, align 4
  %result = alloca i32, align 4
  store i8 %u_val, ptr %u_val.addr, align 1
  %0 = load i8, ptr %u_val.addr, align 1
  %conv = zext i8 %0 to i32
  %not = xor i32 %conv, -1
  %conv1 = trunc i32 %not to i8
  store i8 %conv1, ptr %u_val.addr, align 1
  %1 = load i8, ptr %u_val.addr, align 1
  %conv2 = zext i8 %1 to i32
  %and = and i32 %conv2, 15
  %shl = shl i32 %and, 3
  %add = add nsw i32 %shl, 132
  store i32 %add, ptr %temp, align 4
  %2 = load i8, ptr %u_val.addr, align 1
  %conv3 = zext i8 %2 to i32
  %and4 = and i32 %conv3, 112
  %shr = ashr i32 %and4, 4
  %3 = load i32, ptr %temp, align 4
  %shl5 = shl i32 %3, %shr
  store i32 %shl5, ptr %temp, align 4
  %4 = load i8, ptr %u_val.addr, align 1
  %conv6 = zext i8 %4 to i32
  %and7 = and i32 %conv6, 128
  %tobool = icmp ne i32 %and7, 0
  br i1 %tobool, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  %5 = load i32, ptr %temp, align 4
  %sub = sub nsw i32 132, %5
  br label %cond.end

cond.false:                                       ; preds = %entry
  %6 = load i32, ptr %temp, align 4
  %sub8 = sub nsw i32 %6, 132
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %sub, %cond.true ], [ %sub8, %cond.false ]
  store i32 %cond, ptr %result, align 4
  %7 = load i32, ptr %result, align 4
  ret i32 %7
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
