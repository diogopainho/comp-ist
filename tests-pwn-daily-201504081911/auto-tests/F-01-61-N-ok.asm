extern	readi
extern	readd
extern	printi
extern	printd
extern	prints
extern	println
segment	.text
align	4
global	_main:function
_main:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
segment	.data
align	4
x:
	dd	0
segment	.text
segment	.data
align	4
y:
	dd	0
segment	.text
	push	dword 1
	push	dword [esp]
	push	dword $y
	pop	ecx
	pop	eax
	mov	[ecx], eax
_L3:
	push	dword $y
	pop	eax
	push	dword [eax]
	push	dword 3
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setle	cl
	mov	[esp], ecx
	pop	eax
	cmp	eax, byte 0
	je	near _L4
	push	dword 1
	push	dword [esp]
	push	dword $x
	pop	ecx
	pop	eax
	mov	[ecx], eax
_L6:
	push	dword $x
	pop	eax
	push	dword [eax]
	push	dword 6
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setle	cl
	mov	[esp], ecx
	pop	eax
	cmp	eax, byte 0
	je	near _L7
	push	dword $y
	pop	eax
	push	dword [eax]
	push	dword 2
	pop	ecx
	pop	eax
	cdq
	idiv	ecx
	push	edx
	push	dword 1
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
	pop	eax
	cmp	eax, byte 0
	je	near _L9
	push	dword 1
	jmp	dword _L10
_L9:
	push	dword $x
	pop	eax
	push	dword [eax]
	call	printi
	add	esp, 4
_L10:
_L8:
	push	dword $x
	pop	eax
	push	dword [eax]
	push	dword 1
	pop	eax
	add	dword [esp], eax
	push	dword [esp]
	push	dword $x
	pop	ecx
	pop	eax
	mov	[ecx], eax
	jmp	dword _L6
_L7:
_L5:
	push	dword $y
	pop	eax
	push	dword [eax]
	push	dword 1
	pop	eax
	add	dword [esp], eax
	push	dword [esp]
	push	dword $y
	pop	ecx
	pop	eax
	mov	[ecx], eax
	jmp	dword _L3
_L4:
	push	dword 0
	lea	eax, [ebp+-4]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	pop	eax
	leave
	ret
