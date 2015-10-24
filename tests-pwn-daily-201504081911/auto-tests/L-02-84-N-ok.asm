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
	pop	eax
	cmp	eax, byte 0
	je	near _L1
segment	.data
align	4
f:
	dd	0
segment	.text
	push	dword 0
	push	dword [esp]
	push	dword $f
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	jmp	dword _L2
_L1:
_L2:
	push	dword 9
	lea	eax, [ebp+-4]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
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
global	g:function
g:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
	pop	eax
	cmp	eax, byte 0
	je	near _L3
segment	.data
align	4
g:
	dd	0
segment	.text
	push	dword 0
	push	dword [esp]
	push	dword $g
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	jmp	dword _L4
