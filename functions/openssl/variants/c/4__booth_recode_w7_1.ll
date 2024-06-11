; ModuleID = '/home/javier/Galapagos/functions/openssl/variants/c/4__booth_recode_w7_1.bc'
source_filename = "/home/javier/Galapagos/functions/openssl/variants/c/4__booth_recode_w7_1.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @_booth_recode_w7(i32 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @_booth_recode_w7(i32 noundef %in) #0 {
entry:
  %in.addr = alloca i32, align 4
  %s = alloca i32, align 4
  %d = alloca i32, align 4
  store i32 %in, ptr %in.addr, align 4
  %0 = load i32, ptr %in.addr, align 4
  %shr = lshr i32 %0, 7
  %and = and i32 %shr, 1
  %sub = sub i32 0, %and
  store i32 %sub, ptr %s, align 4
  %1 = load i32, ptr %in.addr, align 4
  %not = xor i32 %1, -1
  store i32 %not, ptr %d, align 4
  %2 = load i32, ptr %d, align 4
  %add = add i32 %2, 1
  %3 = load i32, ptr %s, align 4
  %and1 = and i32 %add, %3
  %4 = load i32, ptr %in.addr, align 4
  %5 = load i32, ptr %s, align 4
  %not2 = xor i32 %5, -1
  %and3 = and i32 %4, %not2
  %or = or i32 %and1, %and3
  store i32 %or, ptr %d, align 4
  %6 = load i32, ptr %d, align 4
  %add4 = add i32 %6, 1
  %shr5 = lshr i32 %add4, 1
  store i32 %shr5, ptr %d, align 4
  %7 = load i32, ptr %d, align 4
  %shl = shl i32 %7, 1
  %8 = load i32, ptr %in.addr, align 4
  %shr6 = lshr i32 %8, 7
  %and7 = and i32 %shr6, 1
  %or8 = or i32 %shl, %and7
  ret i32 %or8
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
