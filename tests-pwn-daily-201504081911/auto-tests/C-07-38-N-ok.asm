segment	.data
align	4
x:
	dd	0
segment	.text
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
	push	dword 2
	neg	dword [esp]
	push	dword [esp]
	push	dword $x
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	push	dword 1
	push	dword $x
	pop	eax
	push	dword [eax]
	neg	dword [esp]
	push	dword 3
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
	pop	eax
	add	dword [esp], eax
	call	printi
	add	esp, 4
	push	dword 0
	lea	eax, [ebp+-4]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	pop	eax
	leave
	ret