	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"LIST OF POSSIBLE COMMANDS:\n"
.LC1:
	.string	"\n    %s : %s"
.LC2:
	.string	"\n"
	.text
	.p2align 4
	.type	_HELP, @function
_HELP:
.LFB22:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	movl	$27, %ecx
	movl	$1, %esi
	leaq	.LC0(%rip), %rdx
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	movl	$1, %edi
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	subq	$272, %rsp
	.cfi_def_cfa_offset 304
	movq	%fs:40, %rax
	movq	%rax, 264(%rsp)
	xorl	%eax, %eax
	call	syscall@PLT
	cmpq	$1, funcSize(%rip)
	je	.L2
	leaq	funcMap(%rip), %rbx
	xorl	%ebp, %ebp
	.p2align 4
	.p2align 3
.L3:
	movq	16(%rbx), %r8
	movq	(%rbx), %rcx
	leaq	.LC1(%rip), %rdx
	xorl	%eax, %eax
	movl	$256, %esi
	movq	%rsp, %rdi
	addq	$1, %rbp
	addq	$24, %rbx
	call	snprintf@PLT
	movq	%rsp, %rdx
	movl	$1, %esi
	movl	$1, %edi
	movl	%eax, %ecx
	xorl	%eax, %eax
	call	syscall@PLT
	movl	$50000, %edi
	call	usleep@PLT
	movq	funcSize(%rip), %rax
	subq	$1, %rax
	cmpq	%rax, %rbp
	jb	.L3
.L2:
	movq	264(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L9
	addq	$272, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	movl	$1, %ecx
	movl	$1, %esi
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 24
	leaq	.LC2(%rip), %rdx
	popq	%rbp
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	popq	%r12
	.cfi_def_cfa_offset 8
	jmp	syscall@PLT
.L9:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE22:
	.size	_HELP, .-_HELP
	.section	.rodata.str1.1
.LC3:
	.string	"clear"
.LC4:
	.string	"%s\nemuSHELL %s\n"
.LC5:
	.string	"Please enter your name: "
.LC6:
	.string	"debugpls"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC7:
	.string	"gcc -fsanitize=address -g ./src/main.c ./src/helper.c -o emu_shell.cpu;echo \"Debug Mode Activated.\""
	.section	.rodata.str1.1
.LC8:
	.string	"sleep 1;./emu_shell.cpu"
.LC9:
	.string	"\n%s%% "
.LC10:
	.string	"%s: Invalid Command\n"
	.text
	.p2align 4
	.type	shell, @function
shell:
.LFB23:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$2392, %rsp
	.cfi_def_cfa_offset 2448
	movq	%fs:40, %rdi
	movq	%rdi, 2376(%rsp)
	leaq	.LC3(%rip), %rdi
	call	system@PLT
	leaq	ver(%rip), %r8
	movl	$1531, %esi
	xorl	%eax, %eax
	leaq	title(%rip), %rcx
	leaq	.LC4(%rip), %rdx
	leaq	832(%rsp), %rdi
	call	snprintf@PLT
	movl	$1, %esi
	movl	$1, %edi
	leaq	832(%rsp), %rdx
	movl	%eax, %ecx
	xorl	%eax, %eax
	call	syscall@PLT
	movl	$24, %ecx
	movl	$1, %esi
	xorl	%eax, %eax
	leaq	.LC5(%rip), %rdx
	movl	$1, %edi
	call	syscall@PLT
	xorl	%esi, %esi
	xorl	%edi, %edi
	xorl	%eax, %eax
	movl	$63, %ecx
	leaq	user(%rip), %rdx
	call	syscall@PLT
	movabsq	$8317146201499788644, %rax
	cmpq	%rax, user(%rip)
	je	.L26
.L13:
	leaq	320(%rsp), %rbp
	.p2align 4
	.p2align 3
.L19:
	leaq	user(%rip), %rcx
	leaq	.LC9(%rip), %rdx
	movq	%rsp, %rdi
	xorl	%eax, %eax
	movl	$64, %esi
	call	snprintf@PLT
	movq	%rsp, %rdx
	movl	$1, %esi
	movl	$1, %edi
	movl	%eax, %ecx
	xorl	%eax, %eax
	call	syscall@PLT
	movl	$511, %ecx
	movq	%rbp, %rdx
	xorl	%esi, %esi
	xorl	%edi, %edi
	xorl	%eax, %eax
	call	syscall@PLT
	movb	$0, 320(%rsp,%rax)
	testq	%rax, %rax
	jle	.L14
	cmpb	$10, 319(%rsp,%rax)
	jne	.L14
	movb	$0, 319(%rsp,%rax)
.L14:
	movq	funcSize(%rip), %r15
	testq	%r15, %r15
	je	.L15
	leaq	funcMap(%rip), %r14
	xorl	%ebx, %ebx
	jmp	.L18
	.p2align 4,,10
	.p2align 3
.L16:
	addq	$1, %rbx
	addq	$24, %r14
	cmpq	%r15, %rbx
	je	.L15
.L18:
	movq	(%r14), %rsi
	movq	%rbp, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L16
	movslq	%ebx, %rbx
	leaq	funcMap(%rip), %rcx
	leaq	(%rbx,%rbx,2), %rax
	call	*8(%rcx,%rax,8)
	jmp	.L19
	.p2align 4,,10
	.p2align 3
.L15:
	movq	%rbp, %rcx
	leaq	64(%rsp), %rdi
	movl	$256, %esi
	xorl	%eax, %eax
	leaq	.LC10(%rip), %rdx
	call	snprintf@PLT
	leaq	64(%rsp), %rdx
	movl	$2, %esi
	movl	$1, %edi
	movl	%eax, %ecx
	xorl	%eax, %eax
	call	syscall@PLT
	jmp	.L19
.L26:
	cmpb	$0, 8+user(%rip)
	jne	.L13
	leaq	.LC7(%rip), %rdi
	call	system@PLT
	leaq	.LC8(%rip), %rdi
	call	system@PLT
	jmp	.L13
	.cfi_endproc
.LFE23:
	.size	shell, .-shell
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	leaq	4+bus_storage(%rip), %rcx
	movl	$1, %eax
	movl	$0, 4+bus_storage(%rip)
	.p2align 5
	.p2align 4
	.p2align 3
.L28:
	movl	%eax, (%rcx,%rax,8)
	leaq	1(%rax), %rdx
	addq	$2, %rax
	movl	%edx, (%rcx,%rdx,8)
	cmpq	$65, %rax
	jne	.L28
	call	shell
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.globl	user
	.bss
	.align 32
	.type	user, @object
	.size	user, 64
user:
	.zero	64
	.globl	funcSize
	.data
	.align 8
	.type	funcSize, @object
	.size	funcSize, 8
funcSize:
	.quad	10
	.globl	funcMap
	.section	.rodata.str1.1
.LC11:
	.string	"LOAD"
	.section	.rodata.str1.8
	.align 8
.LC12:
	.string	"Loads a value from an address."
	.section	.rodata.str1.1
.LC13:
	.string	"STORE"
	.section	.rodata.str1.8
	.align 8
.LC14:
	.string	"Stores a value into an address."
	.section	.rodata.str1.1
.LC15:
	.string	"MATH"
	.section	.rodata.str1.8
	.align 8
.LC16:
	.string	"Performs arithmetic operations on any 2 values."
	.section	.rodata.str1.1
.LC17:
	.string	"CLOCK"
.LC18:
	.string	"Shows time and date."
.LC19:
	.string	"EXIT"
	.section	.rodata.str1.8
	.align 8
.LC20:
	.string	"seriously? you don't know what this does??"
	.section	.rodata.str1.1
.LC21:
	.string	"HELP"
.LC22:
	.string	"self-explanatory, again..."
.LC23:
	.string	"PRINT_BUS"
.LC24:
	.string	"prints the entire bus."
.LC25:
	.string	"ECHO"
	.section	.rodata.str1.8
	.align 8
.LC26:
	.string	"Echoes whatever you put after it. Use \"_\" or something instead of space."
	.section	.rodata.str1.1
.LC27:
	.string	"CLEAR"
.LC28:
	.string	"clears your screen"
	.section	.rodata
.LC29:
	.zero	2
	.section	.data.rel,"aw"
	.align 32
	.type	funcMap, @object
	.size	funcMap, 240
funcMap:
	.quad	.LC11
	.quad	_void_LOAD
	.quad	.LC12
	.quad	.LC13
	.quad	_STORE
	.quad	.LC14
	.quad	.LC15
	.quad	_void_MATH
	.quad	.LC16
	.quad	.LC17
	.quad	_CLOCK
	.quad	.LC18
	.quad	.LC19
	.quad	_EXIT
	.quad	.LC20
	.quad	.LC21
	.quad	_HELP
	.quad	.LC22
	.quad	.LC23
	.quad	_PRINT_BUS
	.quad	.LC24
	.quad	.LC25
	.quad	_ECHO
	.quad	.LC26
	.quad	.LC27
	.quad	_CLEAR
	.quad	.LC28
	.quad	.LC29
	.quad	0
	.quad	.LC29
	.globl	bus_storage
	.bss
	.align 32
	.type	bus_storage, @object
	.size	bus_storage, 520
bus_storage:
	.zero	520
	.globl	ver_len
	.data
	.align 4
	.type	ver_len, @object
	.size	ver_len, 4
ver_len:
	.long	29
	.globl	ver
	.align 16
	.type	ver, @object
	.size	ver, 28
ver:
	.string	"v0.0.1-alpha 2025 \"Toronto\""
	.globl	title_len
	.align 4
	.type	title_len, @object
	.size	title_len, 4
title_len:
	.long	1352
	.globl	title
	.align 32
	.type	title, @object
	.size	title, 1352
title:
	.ascii	"\n______________________________________________________/\\\\"
	.ascii	"\\\\\\\\\\\\\\\\\\____/\\\\\\________/\\\\\\__/\\\\\\\\\\\\\\"
	.ascii	"\\\\\\\\\\\\\\\\__/\\\\\\______________/\\\\\\_____________ "
	.ascii	"       \n __________________________________________________"
	.ascii	"__/\\\\\\/////////\\\\\\_\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\"
	.ascii	"///////////__\\/\\\\\\_____________\\/\\\\\\_____________   "
	.ascii	"    \n  ___________________________________________________\\"
	.ascii	"//\\\\\\______\\///__\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\____"
	.ascii	"_________\\/\\\\\\_____________\\/\\\\\\_____________      \n"
	.ascii	"   _____/\\\\\\\\\\\\\\\\_____/\\\\\\\\\\__/\\\\\\\\\\____/\\"
	.ascii	"\\\\____/\\\\\\___\\///"
	.base64	"L1xcXF9fX19fX19fX1wvXFxcXFxcXFxcXFxcXFxcX1wvXFxcXFxcXFxcXFxfX19fX1wvXFxcX19fX19fX19fX19fX1wvXFxcX19fX19fX19fX19fXyAgICAgCiAgICBfX18vXFxcLy8vLy9cXFxfXy9cXFwvLy9cXFxcXC8vL1xcXF9cL1xcXF9fX1wvXFxcX19fX19fXC8vLy9cXFxfX19fX19cL1xcXC8vLy8vLy8vL1xcXF9cL1xcXC8vLy8vLy9fX19fX19cL1xcXF9fX19fX19fX19fX19cL1xcXF9fX19fX19fX19fX18gICAgCiAgICAgX18vXFxcXFxc"
	.base64	"XFxcXFxfX1wvXFxcX1wvL1xcXF9fXC9cXFxfXC9cXFxfX19cL1xcXF9fX19fX19fX1wvLy8vXFxcX19fXC9cXFxfX19fX19fXC9cXFxfXC9cXFxfX19fX19fX19fX19fXC9cXFxfX19fX19fX19fX19fXC9cXFxfX19fX19fX19fX19fICAgCiAgICAgIF9cLy9cXC8vLy8vLy9fX19cL1xcXF9fXC9cXFxfX1wvXFxcX1wvXFxcX19fXC9cXFxfXy9cXFxfX19fX19cLy9cXFxfX1wvXFxcX19fX19fX1wvXFxcX1wvXFxcX19fX19fX19fX19fX1wvXFxcX19f"
	.base64	"X19fX19fX19fX1wvXFxcX19fX19fX19fX19fXyAgCiAgICAgICBfX1wvL1xcXFxcXFxcXFxfXC9cXFxfX1wvXFxcX19cL1xcXF9cLy9cXFxcXFxcXFxfX1wvLy9cXFxcXFxcXFxcXC9fX19cL1xcXF9fX19fX19cL1xcXF9cL1xcXFxcXFxcXFxcXFxcXF9cL1xcXFxcXFxcXFxcXFxcXF9cL1xcXFxcXFxcXFxcXFxcXF8gCiAgICAgICAgX19fXC8vLy8vLy8vLy9fX1wvLy9fX19cLy8vX19fXC8vL19fX1wvLy8vLy8vLy9fX19fX1wvLy8vLy8vLy8vL19f"
	.ascii	"___\\///________\\///__\\///////////////__\\///////////////_"
	.ascii	"_\\///////////////__\n\n"
	.ident	"GCC: (GNU) 15.1.1 20250425"
	.section	.note.GNU-stack,"",@progbits
