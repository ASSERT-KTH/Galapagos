; ModuleID = '/home/javier/Galapagos/functions/openssl/variants/go/0_icbrt64_4.bc'
source_filename = "gomodule"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

module asm "\09.section \22.go_export\22,\22e\22,@progbits"
module asm "\09.ascii \22v3;\\n\22"
module asm "\09.ascii \22package \22"
module asm "\09.ascii \22main\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22pkgpath \22"
module asm "\09.ascii \22main\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22types 2 1\22"
module asm "\09.ascii \22 31\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22type 1 (? <type -8>) <type -8>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22icbrt64\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22x\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -8>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -8>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:712>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/openssl/variants/go/0_icbrt64_4.go:3\\n var r <type -8> = 0  //4\\n { //6\\n  var s <type -11> = 63  //6\\n  { /*for*/ //6\\n   goto $l0 //6\\n   :$l1 //6\\n   { //6\\n    r = (r << $convert(<type -12>, 1 )) //7\\n    var b <type -8> = (((3  * r) * (r + 1 )) + 1 ) //8\\n    { //9\\n     if ((x >> $convert(<type -12>, s)) >= b) { //9\\n      x = (x - (b << $convert(<type -12>, s))) //10\\n      r = (r + $convert(<type -8>, 1 )) //11\\n     } //9\\n    } //12\\n   } //13\\n   { //6\\n    s = (s - $convert(<type -11>, 3 )) //6\\n   } //6\\n   :$l0 //6\\n   if (s >= $convert(<type -11>, 0 )) { //6\\n    goto $l1 //6\\n   } //6\\n  } //6\\n } //13\\n { //15\\n  $ret0 = (r * $convert(<type -8>, 1 )) //15\\n  return //15\\n } //0\\n\22"
module asm "\09.ascii \22checksum 893256DED6A89335F58CE1EF3E16AC5529C1B7DA\\n\22"
module asm "\09.text"

@main..types = constant { i64, [1 x i8*] } zeroinitializer
@go..typelists = internal constant [1 x { i64, [1 x i8*] }*] [{ i64, [1 x i8*] }* @main..types]

; Function Attrs: null_pointer_is_valid
define void @__go_init_main(i8* nest nocapture readnone %nest.2) local_unnamed_addr #0 {
entry:
  call void @runtime.registerTypeDescriptors(i8* nest undef, i64 1, i8* bitcast ([1 x { i64, [1 x i8*] }*]* @go..typelists to i8*))
  ret void
}

; Function Attrs: nofree norecurse nosync nounwind null_pointer_is_valid readnone
define i64 @main.icbrt64(i8* nest nocapture readnone %nest.0, i64 %x) local_unnamed_addr #1 {
entry:
  br label %then.3

then.3:                                           ; preds = %then.3, %entry
  %x.addr.018 = phi i64 [ %x, %entry ], [ %x.addr.1.1, %then.3 ]
  %r.017 = phi i64 [ 0, %entry ], [ %r.1.1, %then.3 ]
  %s.016 = phi i64 [ 63, %entry ], [ %sub.1.1, %then.3 ]
  %shl.0 = shl i64 %r.017, 1
  %mul.0 = mul i64 %r.017, 6
  %add.0 = or i64 %shl.0, 1
  %mul.1 = mul i64 %mul.0, %add.0
  %add.1 = or i64 %mul.1, 1
  %shr.0 = lshr i64 %x.addr.018, %s.016
  %icmp.2.not = icmp ult i64 %shr.0, %add.1
  %shl.1 = shl i64 %add.1, %s.016
  %r.1 = select i1 %icmp.2.not, i64 %shl.0, i64 %add.0
  %sub.0 = select i1 %icmp.2.not, i64 0, i64 %shl.1
  %x.addr.1 = sub i64 %x.addr.018, %sub.0
  %sub.1 = add nsw i64 %s.016, -3
  %shl.0.1 = shl i64 %r.1, 1
  %mul.0.1 = mul i64 %r.1, 6
  %add.0.1 = or i64 %shl.0.1, 1
  %mul.1.1 = mul i64 %mul.0.1, %add.0.1
  %add.1.1 = or i64 %mul.1.1, 1
  %shr.0.1 = lshr i64 %x.addr.1, %sub.1
  %icmp.2.not.1 = icmp ult i64 %shr.0.1, %add.1.1
  %shl.1.1 = shl i64 %add.1.1, %sub.1
  %r.1.1 = select i1 %icmp.2.not.1, i64 %shl.0.1, i64 %add.0.1
  %sub.0.1 = select i1 %icmp.2.not.1, i64 0, i64 %shl.1.1
  %x.addr.1.1 = sub i64 %x.addr.1, %sub.0.1
  %sub.1.1 = add nsw i64 %s.016, -6
  %icmp.3.1 = icmp ugt i64 %sub.1, 2
  br i1 %icmp.3.1, label %then.3, label %else.3

else.3:                                           ; preds = %then.3
  ret i64 %r.1.1
}

; Function Attrs: nofree norecurse nosync nounwind null_pointer_is_valid readnone
define void @main.main(i8* nest nocapture %nest.1) local_unnamed_addr #1 {
entry:
  %call.0 = call i64 @main.icbrt64(i8* nest undef, i64 0)
  ret void
}

; Function Attrs: null_pointer_is_valid
declare void @runtime.registerTypeDescriptors(i8*, i64, i8*) local_unnamed_addr #0

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.value(metadata, metadata, metadata) #2

attributes #0 = { null_pointer_is_valid "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #1 = { nofree norecurse nosync nounwind null_pointer_is_valid readnone "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #2 = { nofree nosync nounwind readnone speculatable willreturn }

!llvm.module.flags = !{!0, !1, !2}

!0 = !{i32 7, !"PIC Level", i32 0}
!1 = !{i32 2, !"Debug Info Version", i32 3}
!2 = !{i32 2, !"Dwarf Version", i32 4}
