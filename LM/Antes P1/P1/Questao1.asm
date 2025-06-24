# $s1 <- n	| $t0 <- 4	| $s0 <- S0	| $s2 <- i

add $fp,$zero,$sp	# Guarda endere�o original de sp em fp

addi $v0,$zero,5	# Leitura de inteiro
syscall			# Chamada ao sistema
add $s1,$zero,$v0	# Armazena valor em $s1

addi $t0,$zero,4	# Armazena o multiplicando 4
addi $t1,$zero,-1	# Armazena -1 para inverter sinal
mul $t3,$s1,$t0		# Multiplica n por 4 = quantidade de bytes para ser alocado = n * 4
mul $t3,$t3,$t1		# Inverte sinal dos bytes

add $sp,$sp,$t3		# Aloca a quantidade de bytes necess�rio
add $s0,$sp,4		# Salva inicio do vetor em $s0 apontando para primeira posi��o vazia

# Leitura dos valores
add $s2,$zero,$zero	# $s2 ser� o i de incremento
INICIO_LEITURA:
	slt $t1,$s2,$s1			# Verifica se i � menor que n
	beq $t1,$zero,FIM_LEITURA	# Pula para fim do la�o
	
	addi $v0,$zero,5	# Leitura de inteiro
	syscall			# Chamada ao sistema
	add $t1,$zero,$v0	# Armazena valor lido em $t1
	
	mul $t2,$s2,$t0		# Calcula a posi��o absoluta
	add $t3,$s0,$t2		# Posi��o absoluta mais quantidade de bytes para ser pulado
	
	sw $t1,0($t3)		# Armazena valor no vetor
	
	addi $s2,$s2,1		# Incrementa i em 1
	
	j INICIO_LEITURA	# Pula para inicio do vetor
FIM_LEITURA:

# Exibi��o dos valores
add $s2,$zero,$zero	# $s2 ser� o i de incremento
INICIO_PRINT:
	slt $t1,$s2,$s1			# Verifica se i � menor que n
	beq $t1,$zero,FIM_PRINT		# Pula para fim do la�o
	
	mul $t2,$s2,$t0		# Calcula a posi��o absoluta
	add $t3,$s0,$t2		# Posi��o absoluta mais quantidade de bytes para ser pulado
	
	lw $t1,0($t3)		# L� valor que est� na posi��o calculada
	
	addi $v0,$zero,1	# Leitura de inteiro
	add $a0,$zero,$t1	# Carrega valor para exibi��o 
	syscall			# Chamada ao sistema
	
	addi $v0,$zero,11	# Para printar caractere
	addi $a0,$zero,32	# Espaco em ASCII
	syscall
	
	addi $s2,$s2,1		# Incrementa i em 1
	
	j INICIO_PRINT		# Pula para inicio do vetor
FIM_PRINT:
