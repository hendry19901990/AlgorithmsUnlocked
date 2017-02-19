	.text
	.def	 __dtor__ZStL8__ioinit;
	.scl	3;
	.type	32;
	.endef
	.align	16, 0x90
__dtor__ZStL8__ioinit:                  # @__dtor__ZStL8__ioinit
.Ltmp0:
.seh_proc __dtor__ZStL8__ioinit
# BB#0:                                 # %entry
.Ltmp1:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	rex64 jmp	_ZNSt8ios_base4InitD1Ev # TAILCALL
.Ltmp2:
	.seh_endproc

	.def	 main;
	.scl	2;
	.type	32;
	.endef
	.globl	main
	.align	16, 0x90
main:                                   # @main
.Ltmp3:
.seh_proc main
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp4:
	.seh_pushreg 5
	pushq	%rsi
.Ltmp5:
	.seh_pushreg 6
	pushq	%rdi
.Ltmp6:
	.seh_pushreg 7
	subq	$64, %rsp
.Ltmp7:
	.seh_stackalloc 64
	leaq	64(%rsp), %rbp
.Ltmp8:
	.seh_setframe 5, 64
.Ltmp9:
	.seh_endprologue
	callq	__main
	movq	$0, -24(%rbp)
	leaq	_ZSt4cout(%rip), %rsi
	leaq	L.str(%rip), %rdx
	movl	$33, %r8d
	movq	%rsi, %rcx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	leaq	_ZSt3cin(%rip), %rcx
	leaq	-16(%rbp), %rdx
	callq	_ZNSi10_M_extractIdEERSiRT_
	movq	_ZSt4cout(%rip), %rax
	movq	-24(%rax), %rax
	movq	240(%rax,%rsi), %rdi
	testq	%rdi, %rdi
	je	.LBB1_17
# BB#1:                                 # %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit
	cmpb	$0, 56(%rdi)
	je	.LBB1_3
# BB#2:                                 # %if.then.i
	movb	67(%rdi), %al
	jmp	.LBB1_4
.LBB1_3:                                # %if.end.i
	movq	%rdi, %rcx
	callq	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%rdi), %rax
	movl	$10, %edx
	movq	%rdi, %rcx
	callq	*48(%rax)
.LBB1_4:                                # %_ZNKSt5ctypeIcE5widenEc.exit
	movzbl	%al, %edx
	movq	%rsi, %rcx
	callq	_ZNSo3putEc
	movq	%rax, %rcx
	callq	_ZNSo5flushEv
	leaq	L.str.1(%rip), %rdx
	movl	$34, %r8d
	movq	%rsi, %rcx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	leaq	_ZSt3cin(%rip), %rcx
	leaq	-24(%rbp), %rdx
	callq	_ZNSi10_M_extractIdEERSiRT_
	movq	_ZSt4cout(%rip), %rax
	movq	-24(%rax), %rax
	movq	240(%rax,%rsi), %rsi
	testq	%rsi, %rsi
	je	.LBB1_17
# BB#5:                                 # %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit90
	cmpb	$0, 56(%rsi)
	je	.LBB1_7
# BB#6:                                 # %if.then.i.65
	movb	67(%rsi), %al
	jmp	.LBB1_8
.LBB1_7:                                # %if.end.i.69
	movq	%rsi, %rcx
	callq	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%rsi), %rax
	movl	$10, %edx
	movq	%rsi, %rcx
	callq	*48(%rax)
.LBB1_8:                                # %_ZNKSt5ctypeIcE5widenEc.exit71
	movzbl	%al, %edx
	leaq	_ZSt4cout(%rip), %rsi
	movq	%rsi, %rcx
	callq	_ZNSo3putEc
	movq	%rax, %rcx
	callq	_ZNSo5flushEv
	leaq	L.str.2(%rip), %rdx
	movl	$22, %r8d
	movq	%rsi, %rcx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movsd	-16(%rbp), %xmm1        # xmm1 = mem[0],zero
	movq	%rsi, %rcx
	callq	_ZNSo9_M_insertIdEERSoT_
	movq	%rax, %rsi
	leaq	L.str.3(%rip), %rdi
	movl	$11, %r8d
	movq	%rsi, %rcx
	movq	%rdi, %rdx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	leaq	-16(%rbp), %rdx
	movq	%rsi, %rcx
	callq	_ZNSo9_M_insertIPKvEERSoT_
	movq	%rax, %rsi
	leaq	L.str.4(%rip), %rdx
	movl	$3, %r8d
	movq	%rsi, %rcx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movsd	-24(%rbp), %xmm1        # xmm1 = mem[0],zero
	movq	%rsi, %rcx
	callq	_ZNSo9_M_insertIdEERSoT_
	movq	%rax, %rsi
	movl	$11, %r8d
	movq	%rsi, %rcx
	movq	%rdi, %rdx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	leaq	-24(%rbp), %rdx
	movq	%rsi, %rcx
	callq	_ZNSo9_M_insertIPKvEERSoT_
	movq	%rax, %rsi
	leaq	L.str.5(%rip), %rdx
	movl	$3, %r8d
	movq	%rsi, %rcx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movsd	-16(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	-24(%rbp), %xmm1        # xmm1 = mem[0],zero
	movq	$0, -8(%rbp)
	xorpd	%xmm2, %xmm2
	ucomisd	%xmm2, %xmm1
	jbe	.LBB1_12
# BB#9:
	movl	$1, %eax
	.align	16, 0x90
.LBB1_10:                               # %for.body.i
                                        # =>This Inner Loop Header: Depth=1
	addsd	%xmm0, %xmm2
	xorps	%xmm3, %xmm3
	cvtsi2sdl	%eax, %xmm3
	incl	%eax
	ucomisd	%xmm3, %xmm1
	ja	.LBB1_10
# BB#11:                                # %for.cond.for.cond.cleanup_crit_edge.i
	movsd	%xmm2, -8(%rbp)
.LBB1_12:                               # %_Z8multiplydd.exit
	leaq	_ZSt4cout(%rip), %rdi
	leaq	L.str.6(%rip), %rdx
	movl	$12, %r8d
	movq	%rdi, %rcx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	leaq	-8(%rbp), %rdx
	movq	%rdi, %rcx
	callq	_ZNSo9_M_insertIPKvEERSoT_
	leaq	L.str.5(%rip), %rdx
	movl	$3, %r8d
	movq	%rax, %rcx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movsd	-8(%rbp), %xmm1         # xmm1 = mem[0],zero
	movq	%rsi, %rcx
	callq	_ZNSo9_M_insertIdEERSoT_
	movq	%rax, %rsi
	movq	(%rsi), %rax
	movq	-24(%rax), %rax
	movq	240(%rsi,%rax), %rdi
	testq	%rdi, %rdi
	je	.LBB1_17
# BB#13:                                # %_ZSt13__check_facetISt5ctypeIcEERKT_PS3_.exit94
	cmpb	$0, 56(%rdi)
	je	.LBB1_15
# BB#14:                                # %if.then.i.77
	movb	67(%rdi), %al
	jmp	.LBB1_16
.LBB1_15:                               # %if.end.i.81
	movq	%rdi, %rcx
	callq	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%rdi), %rax
	movl	$10, %edx
	movq	%rdi, %rcx
	callq	*48(%rax)
.LBB1_16:                               # %_ZNKSt5ctypeIcE5widenEc.exit83
	movzbl	%al, %edx
	movq	%rsi, %rcx
	callq	_ZNSo3putEc
	movq	%rax, %rcx
	callq	_ZNSo5flushEv
	xorl	%eax, %eax
	addq	$64, %rsp
	popq	%rdi
	popq	%rsi
	popq	%rbp
	retq
.LBB1_17:                               # %if.then.i.92
	callq	_ZSt16__throw_bad_castv
	ud2
.Ltmp10:
	.seh_endproc

	.def	 _Z8multiplydd;
	.scl	2;
	.type	32;
	.endef
	.globl	_Z8multiplydd
	.align	16, 0x90
_Z8multiplydd:                          # @_Z8multiplydd
.Ltmp11:
.seh_proc _Z8multiplydd
# BB#0:                                 # %entry
	pushq	%rsi
.Ltmp12:
	.seh_pushreg 6
	subq	$48, %rsp
.Ltmp13:
	.seh_stackalloc 48
.Ltmp14:
	.seh_endprologue
	movq	$0, 40(%rsp)
	xorpd	%xmm2, %xmm2
	ucomisd	%xmm2, %xmm1
	jbe	.LBB2_4
# BB#1:
	movl	$1, %eax
	.align	16, 0x90
.LBB2_2:                                # %for.body
                                        # =>This Inner Loop Header: Depth=1
	addsd	%xmm0, %xmm2
	xorps	%xmm3, %xmm3
	cvtsi2sdl	%eax, %xmm3
	incl	%eax
	ucomisd	%xmm3, %xmm1
	ja	.LBB2_2
# BB#3:                                 # %for.cond.for.cond.cleanup_crit_edge
	movsd	%xmm2, 40(%rsp)
.LBB2_4:                                # %for.cond.cleanup
	leaq	_ZSt4cout(%rip), %rsi
	leaq	L.str.6(%rip), %rdx
	movl	$12, %r8d
	movq	%rsi, %rcx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	leaq	40(%rsp), %rdx
	movq	%rsi, %rcx
	callq	_ZNSo9_M_insertIPKvEERSoT_
	leaq	L.str.5(%rip), %rdx
	movl	$3, %r8d
	movq	%rax, %rcx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	movsd	40(%rsp), %xmm0         # xmm0 = mem[0],zero
	addq	$48, %rsp
	popq	%rsi
	retq
.Ltmp15:
	.seh_endproc

	.def	 _GLOBAL__sub_I_main.cpp;
	.scl	3;
	.type	32;
	.endef
	.align	16, 0x90
_GLOBAL__sub_I_main.cpp:                # @_GLOBAL__sub_I_main.cpp
.Ltmp16:
.seh_proc _GLOBAL__sub_I_main.cpp
# BB#0:                                 # %entry
	subq	$40, %rsp
.Ltmp17:
	.seh_stackalloc 40
.Ltmp18:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	callq	_ZNSt8ios_base4InitC1Ev
	leaq	__dtor__ZStL8__ioinit(%rip), %rcx
	addq	$40, %rsp
	rex64 jmp	atexit          # TAILCALL
.Ltmp19:
	.seh_endproc

	.lcomm	_ZStL8__ioinit,1        # @_ZStL8__ioinit
	.section	.rdata,"dr"
L.str:                                  # @.str
	.asciz	"Enter value of c (first number): "

L.str.1:                                # @.str.1
	.asciz	"Enter value of d (second number): "

L.str.2:                                # @.str.2
	.asciz	"Value of (c x d) i.e, "

L.str.3:                                # @.str.3
	.asciz	" located @ "

L.str.4:                                # @.str.4
	.asciz	" x "

L.str.5:                                # @.str.5
	.asciz	" = "

L.str.6:                                # @.str.6
	.asciz	" Value at : "

	.section	.ctors,"dw"
	.align	8
	.quad	_GLOBAL__sub_I_main.cpp

