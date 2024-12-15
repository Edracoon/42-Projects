section .text
	global _ft_strlen

_ft_strlen:
	mov rcx,0
boucle:
	cmp byte[rdi+rcx],0
	je return
	inc rcx
	jmp boucle
return:
	mov rax,rcx
	ret