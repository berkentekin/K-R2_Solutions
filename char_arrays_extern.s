	.file	"char_arrays_extern.c"
	.text
	.globl	max
	.bss
	.align 4
	.type	max, @object
	.size	max, 4
max:
	.zero	4
	.globl	line
	.align 32
	.type	line, @object
	.size	line, 1000
line:
	.zero	1000
	.globl	longest
	.align 32
	.type	longest, @object
	.size	longest, 1000
longest:
	.zero	1000
	.section	.rodata
.LC0:
	.string	"%s"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, max(%rip)
	jmp	.L2
.L3:
	movl	max(%rip), %eax
	cmpl	%eax, -4(%rbp)
	jle	.L2
	movl	-4(%rbp), %eax
	movl	%eax, max(%rip)
	call	copy
.L2:
	call	get_line
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jne	.L3
	movl	max(%rip), %eax
	testl	%eax, %eax
	jle	.L4
	movl	$longest, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
.L4:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	get_line
	.type	get_line, @function
get_line:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	jmp	.L7
.L9:
	movl	-8(%rbp), %eax
	movl	%eax, %edx
	movl	-4(%rbp), %eax
	cltq
	movb	%dl, line(%rax)
	addl	$1, -4(%rbp)
.L7:
	cmpl	$998, -4(%rbp)
	jg	.L8
	call	getchar
	movl	%eax, -8(%rbp)
	cmpl	$-1, -8(%rbp)
	je	.L8
	cmpl	$10, -8(%rbp)
	jne	.L9
.L8:
	movl	-4(%rbp), %eax
	cltq
	movb	$10, line(%rax)
	movl	-4(%rbp), %eax
	addl	$1, %eax
	cltq
	movb	$0, line(%rax)
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	get_line, .-get_line
	.globl	copy
	.type	copy, @function
copy:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, -4(%rbp)
	jmp	.L12
.L13:
	addl	$1, -4(%rbp)
.L12:
	movl	-4(%rbp), %eax
	cltq
	movzbl	line(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	movb	%dl, longest(%rax)
	movl	-4(%rbp), %eax
	cltq
	movzbl	longest(%rax), %eax
	testb	%al, %al
	jne	.L13
	nop
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	copy, .-copy
	.ident	"GCC: (GNU) 11.1.1 20210531 (Red Hat 11.1.1-3)"
	.section	.note.GNU-stack,"",@progbits
