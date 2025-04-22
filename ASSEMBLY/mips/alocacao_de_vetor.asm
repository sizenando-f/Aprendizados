add $fp,$zero,$sp	# Guarda o $sp original em $fp para restabelecer a pilha

#int S0[5] -> equivalente
add $s0,$sp,$zero	# Guarda a posição do início do primeiro vetor em $s0
addi $sp,$sp,-20	# Vai para a posição inicial do segundo vetor (-20 pois o vetor desce no endereço, 
			# é o do maior para o menor.)
#int S1[5] -> equivalente
add $s1,$sp,$zero	# Guarda a posição do início do segundo vetor em $s1
addi $sp,$sp,-20	# Vai para a posição final do segundo vetor

#int i - > $s2
# for(i = 0; i < 5; i++)
addi $s2,$zero,0		# Inicializa i
addi $t0,$zero,4
FOR_1:
	slti $t1,$s2,5		# Compara se é menor que 5
	beq $t1,$zero,FIM_FOR_1	# Pula se for maior que 5
#	leia $v0
	addi $v0,$zero,5	# Preparando para ler um inteiro
	syscall			# Faz a chamada ao sistema
#	S0[i] = $v0
	mul $t1,$t0,$s2		# Cálculo de deslocamento			$t1 = 4 * $s2
	add $t1,$t1,$s0		# Soma do endereço básico com o deslocamento	$t1 = $t1 + Endereço básico
	sw $v0,0($t1)		#
	
	addi $s2,$s2,1		# Incrementa i
	j FOR_1			# Volta ao inicio do forr
FIM_FOR_1:

#addi $sp,$sp,40	# Volta para o início do primeiro vetor (adiciona 40 para subir de volta para o início)
add $sp,$zero,$fp	# Mesma coisa porém mais prático e sem precisar fazer cálculo de endereçamento	

addi $v0,$zero,10
syscall

# Tarefa, copiar elementos do primeiro vetor para o segundo e imprimir o segundo vetor 
