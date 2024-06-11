; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/c/1_b64_byte_to_urlsafe_char_4.bc'
source_filename = "/home/javier/Galapagos/functions/libsodium/variants/c/1_b64_byte_to_urlsafe_char_4.c"
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
  %x.addr = alloca i32, align 4
  store i32 %x, ptr %x.addr, align 4
  %0 = load i32, ptr %x.addr, align 4
  %cmp = icmp ult i32 %0, 26
  br i1 %cmp, label %cond.true, label %cond.false

cond.true:                                        ; preds = %entry
  %1 = load i32, ptr %x.addr, align 4
  %add = add i32 %1, 65
  br label %cond.end14

cond.false:                                       ; preds = %entry
  %2 = load i32, ptr %x.addr, align 4
  %cmp1 = icmp ult i32 %2, 52
  br i1 %cmp1, label %cond.true2, label %cond.false4

cond.true2:                                       ; preds = %cond.false
  %3 = load i32, ptr %x.addr, align 4
  %sub = sub i32 %3, 26
  %add3 = add i32 %sub, 97
  br label %cond.end12

cond.false4:                                      ; preds = %cond.false
  %4 = load i32, ptr %x.addr, align 4
  %cmp5 = icmp ult i32 %4, 62
  br i1 %cmp5, label %cond.true6, label %cond.false9

cond.true6:                                       ; preds = %cond.false4
  %5 = load i32, ptr %x.addr, align 4
  %sub7 = sub i32 %5, 52
  %add8 = add i32 %sub7, 48
  br label %cond.end

cond.false9:                                      ; preds = %cond.false4
  %6 = load i32, ptr %x.addr, align 4
  %cmp10 = icmp eq i32 %6, 62
  %7 = zext i1 %cmp10 to i64
  %cond = select i1 %cmp10, i32 45, i32 95
  br label %cond.end

cond.end:                                         ; preds = %cond.false9, %cond.true6
  %cond11 = phi i32 [ %add8, %cond.true6 ], [ %cond, %cond.false9 ]
  br label %cond.end12

cond.end12:                                       ; preds = %cond.end, %cond.true2
  %cond13 = phi i32 [ %add3, %cond.true2 ], [ %cond11, %cond.end ]
  br label %cond.end14

cond.end14:                                       ; preds = %cond.end12, %cond.true
  %cond15 = phi i32 [ %add, %cond.true ], [ %cond13, %cond.end12 ]
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
