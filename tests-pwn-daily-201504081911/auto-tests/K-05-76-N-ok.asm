extern	readi
extern	readd
extern	printi
extern	printd
extern	prints
extern	println
segment	.text
align	4
global	f:function
f:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
segment	.data
align	4
x:
	dd	0
segment	.text
	push	dword 5
	push	dword [esp]
	push	dword $x
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
segment	.data
align	4
f:
	dd	0
segment	.text
	push	dword 1
	push	dword $x
	pop	eax
	push	dword [eax]
	pop	eax
	add	dword [esp], eax
	push	dword [esp]
	push	dword $f
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	push	dword 0
	pop	eax
	leave
	ret
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
