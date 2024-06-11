; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/c/0_b64_byte_to_char_5.bc'
source_filename = "/home/javier/Galapagos/functions/libsodium/variants/c/0_b64_byte_to_char_5.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @b64_byte_to_char(i32 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @b64_byte_to_char(i32 noundef %x) #0 {
entry:
  %retval = alloca i32, align 4
  %x.addr = alloca i32, align 4
  store i32 %x, ptr %x.addr, align 4
  %0 = load i32, ptr %x.addr, align 4
  %cmp = icmp eq i32 %0, 62
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  store i32 43, ptr %retval, align 4
  br label %return

if.end:                                           ; preds = %entry
  %1 = load i32, ptr %x.addr, align 4
  %cmp1 = icmp eq i32 %1, 63
  br i1 %cmp1, label %if.then2, label %if.end3

if.then2:                                         ; preds = %if.end
  store i32 47, ptr %retval, align 4
  br label %return

if.end3:                                          ; preds = %if.end
  %2 = load i32, ptr %x.addr, align 4
  %cmp4 = icmp ult i32 %2, 26
  br i1 %cmp4, label %cond.true, label %cond.false

cond.true:                                        ; preds = %if.end3
  %3 = load i32, ptr %x.addr, align 4
  %add = add i32 %3, 65
  br label %cond.end11

cond.false:                                       ; preds = %if.end3
  %4 = load i32, ptr %x.addr, align 4
  %cmp5 = icmp ult i32 %4, 52
  br i1 %cmp5, label %cond.true6, label %cond.false8

cond.true6:                                       ; preds = %cond.false
  %5 = load i32, ptr %x.addr, align 4
  %sub = sub i32 %5, 26
  %add7 = add i32 %sub, 97
  br label %cond.end

cond.false8:                                      ; preds = %cond.false
  %6 = load i32, ptr %x.addr, align 4
  %sub9 = sub i32 %6, 52
  %add10 = add i32 %sub9, 48
  br label %cond.end

cond.end:                                         ; preds = %cond.false8, %cond.true6
  %cond = phi i32 [ %add7, %cond.true6 ], [ %add10, %cond.false8 ]
  br label %cond.end11

cond.end11:                                       ; preds = %cond.end, %cond.true
  %cond12 = phi i32 [ %add, %cond.true ], [ %cond, %cond.end ]
  store i32 %cond12, ptr %retval, align 4
  br label %return

return:                                           ; preds = %cond.end11, %if.then2, %if.then
  %7 = load i32, ptr %retval, align 4
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
