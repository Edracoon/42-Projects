section .text
	global _ft_write
	extern ___error

_ft_write:
	mov rax,0x2000004
	syscall
	jc error
	jmp return
error:
	push rax
	call ___error
	pop qword[rax]
	mov rax,-1
	ret
return:
	ret
