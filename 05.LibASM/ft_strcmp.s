section .text
	global _ft_strcmp

_ft_strcmp:
	mov rcx,0
boucle_cmp:
	cmp byte [rsi + rcx],0
	jz return
	cmp byte [rdi + rcx],0
	jz return
	mov al, byte[rsi + rcx]
	cmp al, byte [rdi + rcx]
	jne return
	inc rcx
	jmp boucle_cmp
return:
	movzx rdx, byte [rsi + rcx]
	movzx rax, byte [rdi + rcx]
	sub rax, rdx
	ret