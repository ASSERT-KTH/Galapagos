; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/c/1_b64_byte_to_urlsafe_char_8.bc'
source_filename = "/home/javier/Galapagos/functions/libsodium/variants/c/1_b64_byte_to_urlsafe_char_8.c"
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
  %retval = alloca i32, align 4
  %x.addr = alloca i32, align 4
  store i32 %x, ptr %x.addr, align 4
  %0 = load i32, ptr %x.addr, align 4
  switch i32 %0, label %sw.epilog [
    i32 0, label %sw.bb
    i32 1, label %sw.bb
    i32 2, label %sw.bb
    i32 3, label %sw.bb
    i32 4, label %sw.bb
    i32 5, label %sw.bb
    i32 6, label %sw.bb
    i32 7, label %sw.bb
    i32 8, label %sw.bb
    i32 9, label %sw.bb
    i32 10, label %sw.bb
    i32 11, label %sw.bb
    i32 12, label %sw.bb
    i32 13, label %sw.bb
    i32 14, label %sw.bb
    i32 15, label %sw.bb
    i32 16, label %sw.bb
    i32 17, label %sw.bb
    i32 18, label %sw.bb
    i32 19, label %sw.bb
    i32 20, label %sw.bb
    i32 21, label %sw.bb
    i32 22, label %sw.bb
    i32 23, label %sw.bb
    i32 24, label %sw.bb
    i32 25, label %sw.bb
    i32 26, label %sw.bb1
    i32 27, label %sw.bb1
    i32 28, label %sw.bb1
    i32 29, label %sw.bb1
    i32 30, label %sw.bb1
    i32 31, label %sw.bb1
    i32 32, label %sw.bb1
    i32 33, label %sw.bb1
    i32 34, label %sw.bb1
    i32 35, label %sw.bb1
    i32 36, label %sw.bb1
    i32 37, label %sw.bb1
    i32 38, label %sw.bb1
    i32 39, label %sw.bb1
    i32 40, label %sw.bb1
    i32 41, label %sw.bb1
    i32 42, label %sw.bb1
    i32 43, label %sw.bb1
    i32 44, label %sw.bb1
    i32 45, label %sw.bb1
    i32 46, label %sw.bb1
    i32 47, label %sw.bb1
    i32 48, label %sw.bb1
    i32 49, label %sw.bb1
    i32 50, label %sw.bb1
    i32 51, label %sw.bb1
    i32 52, label %sw.bb3
    i32 53, label %sw.bb3
    i32 54, label %sw.bb3
    i32 55, label %sw.bb3
    i32 56, label %sw.bb3
    i32 57, label %sw.bb3
    i32 58, label %sw.bb3
    i32 59, label %sw.bb3
    i32 60, label %sw.bb3
    i32 61, label %sw.bb3
    i32 62, label %sw.bb6
    i32 63, label %sw.bb7
  ]

sw.bb:                                            ; preds = %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry
  %1 = load i32, ptr %x.addr, align 4
  %add = add i32 %1, 65
  store i32 %add, ptr %retval, align 4
  br label %return

sw.bb1:                                           ; preds = %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry
  %2 = load i32, ptr %x.addr, align 4
  %sub = sub i32 %2, 26
  %add2 = add i32 %sub, 97
  store i32 %add2, ptr %retval, align 4
  br label %return

sw.bb3:                                           ; preds = %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry, %entry
  %3 = load i32, ptr %x.addr, align 4
  %sub4 = sub i32 %3, 52
  %add5 = add i32 %sub4, 48
  store i32 %add5, ptr %retval, align 4
  br label %return

sw.bb6:                                           ; preds = %entry
  store i32 45, ptr %retval, align 4
  br label %return

sw.bb7:                                           ; preds = %entry
  store i32 95, ptr %retval, align 4
  br label %return

sw.epilog:                                        ; preds = %entry
  store i32 -1, ptr %retval, align 4
  br label %return

return:                                           ; preds = %sw.epilog, %sw.bb7, %sw.bb6, %sw.bb3, %sw.bb1, %sw.bb
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
