# ALOCAÇÃO DINÂMICA (syscall 9, recebe em v0 o endereço alocado, a0 vai a quantidade de bytes para ser alocado)
# int *V1, *V2, i; //	V1 -> $s0, V2 -> $s1, i -> $s2

# V1 = new int[10]
addi $v0,$zero,9
addi $a0,$zero,40
syscall
add $s0,$zero,$v0

# V2 = new int[10]
addi $v0,$zero,9
addi $a0,$zero,40
syscall
add $s1,$zero,$v0

addi $t0,$zero,4	# Para fazer a multiplicação
# for (i = 0; i < 10; ++i){
add $s2,$zero,$zero
FOR_LEITURA:
	slti $t1,$s2,10
	beq $t1,$zero,FIM_FOR_LEITURA
	
#	leia V1[i];
	addi $v0,$zero,5	# Para ler inteiro
	syscall			# Lê o inteiro
	
	add $t1,$zero,$s0	# Carrega endereço base
	mul $t2,$s2,$t0		# i * 4
	add $t1,$t1,$t2		# Endereço absoluto onde será feito a escrita
	
	sw $v0,0($t1)		# Salva valor lido em v0 para a posição absoluta descoberta
	addi $s2,$s2,1
	j FOR_LEITURA
#}
FIM_FOR_LEITURA:

addi $t0,$zero,4
# for (i = 0; i < 10; ++i){
add $s2,$zero,$zero
FOR_INVERTE:
	slti $t1,$s2,10
	beq $t1,$zero,FIM_FOR_INVERTE
	
	# Calcula o deslocamento
	mul $t1,$s2,$t0	# i * 4
	addi $t2,$zero,9
	sub $t2,$t2,$s2 # 9 - i
	mul $t2,$t2,$t0	# (9 - i) * 4
	
	# Calcula os endereços absolutos
	add $t1,$s1,$t1
	add $t2,$s0,$t2
	
#	V2[i] = V1[9-i];

	lw $t3,0($t2)
	sw $t3,0($t1)
	
	addi $s2,$s2,1
	j FOR_INVERTE
#}
FIM_FOR_INVERTE:


addi $t0,$zero,4
addi $s2,$zero,1
FOR_SOMA:
	slti $t1,$s2,10
	beq $t1,$zero,FIM_FOR_SOMA
	
	mul $t1,$s2,$t0
	add $t1,$s0,$t1
	
	lw $t2,0($t1)
	lw $t3,-4($t1)
	
	add $t2,$t2,$t3
	sw $t2,0($t1)
	
	addi $s2,$s2,1
	j FOR_SOMA
FIM_FOR_SOMA:
