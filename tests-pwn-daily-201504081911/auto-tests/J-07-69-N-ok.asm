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
	sub	esp, 0
segment	.data
align	4
pwn:
	push	dword 3
	push	dword $pwn
	pop	eax
	push	dword [eax]
	add	esp, 4
	push	dword $pwn
	pop	eax
	push	dword [eax]
	call	printi
	add	esp, 4
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
	call	f
	push	dword 0
	lea	eax, [ebp+-4]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	pop	eax
	leave
	ret
