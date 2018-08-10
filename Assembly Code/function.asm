global _start

section .text

_start :
	push 21
	call timesfunc
	mov ebx, eax
	mov eax, 1
	int 0x80

timesfunc :
	push ebp
	mov ebp, esp
	mov eax, [ebp + 8]
	add eax, eax
	add eax, eax
	xor eax, eax
	mov esp, ebp
	pop ebp
	ret
