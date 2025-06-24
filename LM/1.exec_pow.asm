# Procedimentos
# Expoente

# Ler A e B: A -> $s0 | B -> $s1

addi $v0,$zero,5
syscall
add $s0,$zero,$v0

addi $v0,$zero,5
syscall
add $s1,$zero,$v0

# C = pow(a,b): C -> $s2
add $a0,$zero,$s0
add $a1,$zero,$s1
jal PROC_POW
add $s2,$zero,$v0

# Impressão do C
addi $v0,$zero,1
add $a0,$zero,$s2
syscall

# return 0;
addi $v0,$zero,10
syscall

PROC_POW:
# i -> $s0 | res -> $s1
# int pow(int x, int y){
#	int i, res = 1;
# SALVAMENTO DOS REGISTRADORES $S0 E $S1 (pilha)
# Usar fp por que são poucos valores para salvar
	add $fp,$zero,$sp
	addi $sp,$sp,-8
	sw $s0,0($fp)
	sw $s1,-4($fp)

	addi $s1,$zero,1
	addi $s0,$zero,0	
#	for(int i = 0; i < y; ++i)
	PROC_POW_FOR:
		slt $t0,$s0,$a1
		beq $t0,$zero,PROC_POW_FIM_FOR
#		res *= x;
		mul $s1,$s1,$a0
		addi $s0,$s0,1
		j PROC_POW_FOR
	PROC_POW_FIM_FOR:
	add $v0,$zero,$s1
# RECUPERAR REGISTRADORES $S0 E $S1
	lw $s0,0($fp)
	lw $s1,-4($fp)
	add $sp,$zero,$fp
	jr $ra
#	return res;
# }
	
	
	jr $ra			# ra guarda pc + 4 do endereço de onde foi chamado o jal
# 	return x + y;
#}