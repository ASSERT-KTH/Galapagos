; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/c/0_b64_byte_to_char_2.bc'
source_filename = "/home/javier/Galapagos/functions/libsodium/variants/c/0_b64_byte_to_char_2.c"
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
  %x.addr = alloca i32, align 4
  store i32 %x, ptr %x.addr, align 4
  %0 = load i32, ptr %x.addr, align 4
  %cmp = icmp ult i32 %0, 26
  %conv = zext i1 %cmp to i32
  %1 = load i32, ptr %x.addr, align 4
  %add = add i32 %1, 65
  %mul = mul i32 %conv, %add
  %2 = load i32, ptr %x.addr, align 4
  %cmp1 = icmp uge i32 %2, 26
  br i1 %cmp1, label %land.rhs, label %land.end

land.rhs:                                         ; preds = %entry
  %3 = load i32, ptr %x.addr, align 4
  %cmp3 = icmp ult i32 %3, 52
  br label %land.end

land.end:                                         ; preds = %land.rhs, %entry
  %4 = phi i1 [ false, %entry ], [ %cmp3, %land.rhs ]
  %land.ext = zext i1 %4 to i32
  %5 = load i32, ptr %x.addr, align 4
  %sub = sub i32 %5, 26
  %add5 = add i32 %sub, 97
  %mul6 = mul i32 %land.ext, %add5
  %or = or i32 %mul, %mul6
  %6 = load i32, ptr %x.addr, align 4
  %cmp7 = icmp uge i32 %6, 52
  br i1 %cmp7, label %land.rhs9, label %land.end12

land.rhs9:                                        ; preds = %land.end
  %7 = load i32, ptr %x.addr, align 4
  %cmp10 = icmp ult i32 %7, 62
  br label %land.end12

land.end12:                                       ; preds = %land.rhs9, %land.end
  %8 = phi i1 [ false, %land.end ], [ %cmp10, %land.rhs9 ]
  %land.ext13 = zext i1 %8 to i32
  %9 = load i32, ptr %x.addr, align 4
  %sub14 = sub i32 %9, 52
  %add15 = add i32 %sub14, 48
  %mul16 = mul i32 %land.ext13, %add15
  %or17 = or i32 %or, %mul16
  %10 = load i32, ptr %x.addr, align 4
  %cmp18 = icmp eq i32 %10, 62
  %conv19 = zext i1 %cmp18 to i32
  %mul20 = mul nsw i32 %conv19, 43
  %or21 = or i32 %or17, %mul20
  %11 = load i32, ptr %x.addr, align 4
  %cmp22 = icmp eq i32 %11, 63
  %conv23 = zext i1 %cmp22 to i32
  %mul24 = mul nsw i32 %conv23, 47
  %or25 = or i32 %or21, %mul24
  ret i32 %or25
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
