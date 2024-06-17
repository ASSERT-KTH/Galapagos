; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/c/0_alaw_to_s16_8.bc'
source_filename = "/home/javier/Galapagos/functions/alsa-lib/variants/c/0_alaw_to_s16_8.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @alaw_to_s16(i8 noundef zeroext 97)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @alaw_to_s16(i8 noundef zeroext %a_val) #0 {
entry:
  %a_val.addr = alloca i8, align 1
  %t = alloca i32, align 4
  %seg = alloca i32, align 4
  store i8 %a_val, ptr %a_val.addr, align 1
  %0 = load i8, ptr %a_val.addr, align 1
  %conv = zext i8 %0 to i32
  %xor = xor i32 %conv, 85
  %and = and i32 %xor, 127
  store i32 %and, ptr %t, align 4
  %1 = load i32, ptr %t, align 4
  %and1 = and i32 %1, 112
  %shr = ashr i32 %and1, 4
  store i32 %shr, ptr %seg, align 4
  %2 = load i32, ptr %seg, align 4
  %cmp = icmp eq i32 %2, 0
  br i1 %cmp, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  %3 = load i32, ptr %t, align 4
  %or = or i32 %3, 16
  %shl = shl i32 %or, 4
  br label %cond.end

cond.false:                                       ; preds = %entry
  %4 = load i32, ptr %t, align 4
  %and3 = and i32 %4, 15
  %or4 = or i32 %and3, 16
  %5 = load i32, ptr %seg, align 4
  %add = add nsw i32 %5, 3
  %shl5 = shl i32 %or4, %add
  br label %cond.end

cond.end:                                         ; preds = %cond.false, %cond.true
  %cond = phi i32 [ %shl, %cond.true ], [ %shl5, %cond.false ]
  %add6 = add nsw i32 %cond, 8
  store i32 %add6, ptr %t, align 4
  %6 = load i32, ptr %seg, align 4
  %tobool = icmp ne i32 %6, 0
  br i1 %tobool, label %if.then, label %if.end

if.then:                                          ; preds = %cond.end
  %7 = load i32, ptr %t, align 4
  %add7 = add nsw i32 %7, 256
  store i32 %add7, ptr %t, align 4
  br label %if.end

if.end:                                           ; preds = %if.then, %cond.end
  %8 = load i8, ptr %a_val.addr, align 1
  %conv8 = zext i8 %8 to i32
  %and9 = and i32 %conv8, 128
  %tobool10 = icmp ne i32 %and9, 0
  br i1 %tobool10, label %cond.true11, label %cond.false12

cond.true11:                                      ; preds = %if.end
  %9 = load i32, ptr %t, align 4
  br label %cond.end13

cond.false12:                                     ; preds = %if.end
  %10 = load i32, ptr %t, align 4
  %sub = sub nsw i32 0, %10
  br label %cond.end13

cond.end13:                                       ; preds = %cond.false12, %cond.true11
  %cond14 = phi i32 [ %9, %cond.true11 ], [ %sub, %cond.false12 ]
  ret i32 %cond14
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
