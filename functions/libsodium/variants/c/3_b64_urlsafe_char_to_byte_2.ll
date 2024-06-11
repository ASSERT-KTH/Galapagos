; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/c/3_b64_urlsafe_char_to_byte_2.bc'
source_filename = "/home/javier/Galapagos/functions/libsodium/variants/c/3_b64_urlsafe_char_to_byte_2.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %call = call i32 @b64_urlsafe_char_to_byte(i32 noundef 0)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define internal i32 @b64_urlsafe_char_to_byte(i32 noundef %c) #0 {
entry:
  %retval = alloca i32, align 4
  %c.addr = alloca i32, align 4
  store i32 %c, ptr %c.addr, align 4
  %0 = load i32, ptr %c.addr, align 4
  switch i32 %0, label %sw.default [
    i32 65, label %sw.bb
    i32 66, label %sw.bb
    i32 67, label %sw.bb
    i32 68, label %sw.bb
    i32 69, label %sw.bb
    i32 70, label %sw.bb
    i32 71, label %sw.bb
    i32 72, label %sw.bb
    i32 73, label %sw.bb
    i32 74, label %sw.bb
    i32 75, label %sw.bb
    i32 76, label %sw.bb
    i32 77, label %sw.bb
    i32 78, label %sw.bb
    i32 79, label %sw.bb
    i32 80, label %sw.bb
    i32 81, label %sw.bb
    i32 82, label %sw.bb
    i32 83, label %sw.bb
    i32 84, label %sw.bb
    i32 85, label %sw.bb
    i32 86, label %sw.bb
    i32 87, label %sw.bb
    i32 88, label %sw.bb
    i32 89, label %sw.bb
    i32 90, label %sw.bb
    i32 97, label %sw.bb1
    i32 98, label %sw.bb1
    i32 99, label %sw.bb1
    i32 100, label %sw.bb1
    i32 101, label %sw.bb1
    i32 102, label %sw.bb1
    i32 103, label %sw.bb1
    i32 104, label %sw.bb1
    i32 105, label %sw.bb1
    i32 106, label %sw.bb1
    i32 107, label %sw.bb1
    i32 108, label %sw.bb1
    i32 109, label %sw.bb1
    i32 110, label %sw.bb1
    i32 111, label %sw.bb1
    i32 112, label %sw.bb1
    i32 113, label %sw.bb1
    i32 114, label %sw.bb1
    i32 115, label %sw.bb1
    i32 116, label %sw.bb1
    i32 117, label %sw.bb1
    i32 118, label %sw.bb1
    i32 119, label %sw.bb1
    i32 120, label %sw.bb1
    i32 121, label %sw.bb1
    i32 122, label %sw.bb1
    i32 48, label %sw.bb3
    i32 49, label %sw.bb3
    i32 50, label %sw.bb3
    i32 51, label %sw.bb3
    i32 52, label %sw.bb3
    i32 53, label %sw.bb3
    i32 54, label %sw.bb3
    i32 55, label %sw.bb3
    i32 56, label %sw.bb3
    i32 57, label %sw.bb3
    i32 45, label %sw.bb6
    i32 95, label %sw.bb7
  ]

sw.bb:                                            ; preds = %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry
  %1 = load i32, ptr %c.addr, align 4
  %sub = sub nsw i32 %1, 65
  store i32 %sub, ptr %retval, align 4
  br label %return

sw.bb1:                                           ; preds = %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry
  %2 = load i32, ptr %c.addr, align 4
  %sub2 = sub nsw i32 %2, 97
  %add = add nsw i32 %sub2, 26
  store i32 %add, ptr %retval, align 4
  br label %return

sw.bb3:                                           ; preds = %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry
  %3 = load i32, ptr %c.addr, align 4
  %sub4 = sub nsw i32 %3, 48
  %add5 = add nsw i32 %sub4, 52
  store i32 %add5, ptr %retval, align 4
  br label %return

sw.bb6:                                           ; preds = %entry
  store i32 62, ptr %retval, align 4
  br label %return

sw.bb7:                                           ; preds = %entry
  store i32 63, ptr %retval, align 4
  br label %return

sw.default:                                       ; preds = %entry
  store i32 0, ptr %retval, align 4
  br label %return

return:                                           ; preds = %sw.default, %sw.bb7, %sw.bb6, %sw.bb3, %sw.bb1, %sw.bb
  %4 = load i32, ptr %retval, align 4
  ret i32 %4
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
