section .text
	global _ft_strcpy

_ft_strcpy:
	mov rcx,0
boucle_cpy:
	cmp byte[rsi + rcx],0
	je return
	mov al,[rsi + rcx]
	mov [rdi + rcx],al
	inc rcx
	jmp boucle_cpy
return:
	mov byte[rdi + rcx],0
	mov rax,rdi
	ret
