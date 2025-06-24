add $fp,$zero,$sp	# Guarda o $sp original em $fp para restabelecer a pilha

#int S0[10] -> equivalente (40/4 = 10)
addi $sp,$sp,-40	# Vai para a posição inicial do segundo vetor (-40 pois o vetor desce no endereço, 
			# é o do maior para o menor.)
addi $s0,$sp,4		# Guarda a posição do início do primeiro vetor em $s0 - 4, posição vazia

#int i - > $s2
# for(i = 0; i < 5; i++)
addi $s2,$zero,0		# Inicializa i
addi $t0,$zero,4
# Lendo os valores
FOR_1:
	slti $t1,$s2,10		# Compara se é menor que 10
	beq $t1,$zero,FIM_FOR_1	# Pula se for maior que 5
#	leia $v0
	addi $v0,$zero,5	# Preparando para ler um inteiro
	syscall			# Faz a chamada ao sistema
#	S0[i] = $v0
	mul $t1,$t0,$s2		# Cálculo de deslocamento			$t1 = 4 * $s2 (i)
	add $t1,$t1,$s0		# Soma do endereço básico com o deslocamento	$t1 = $t1 + Endereço básico
	sw $v0,0($t1)		#
	
	addi $s2,$s2,1		# Incrementa i
	j FOR_1			# Volta ao inicio do for
FIM_FOR_1:

# Printar invertido
#int i - > $s2
# for(i = 0; i < 5; i++)
addi $s2,$zero,0		# Inicializa i
addi $t0,$zero,4
# Lendo os valores
FOR_2:
	slti $t1,$s2,10		# Compara se é menor que 10
	beq $t1,$zero,FIM_FOR_2	# Pula se for maior que 5
#	leia $v0
	addi $v0,$zero,5	# Preparando para ler um inteiro
	syscall			# Faz a chamada ao sistema
#	S0[i] = $v0
	mul $t1,$t0,$s2		# Cálculo de deslocamento			$t1 = 4 * $s2 (i)
	add $t1,$t1,$s0		# Soma do endereço básico com o deslocamento	$t1 = $t1 + Endereço básico
	sw $v0,0($t1)		#
	
	addi $s2,$s2,1		# Incrementa i
	j FOR_1			# Volta ao inicio do for
FIM_FOR_2:

# Somatória de cada valor pelo o próximo, quase um fibbonacci
# V1 = 1 2 3 4 5
# saída = 3 6 10 15