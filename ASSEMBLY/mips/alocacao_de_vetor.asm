add $fp,$zero,$sp	# Guarda o $sp original em $fp para restabelecer a pilha

#int S0[5] -> equivalente
add $s0,$sp,$zero	# Guarda a posi��o do in�cio do primeiro vetor em $s0
addi $sp,$sp,-20	# Vai para a posi��o inicial do segundo vetor (-20 pois o vetor desce no endere�o, 
			# � o do maior para o menor.)
#int S1[5] -> equivalente
add $s1,$sp,$zero	# Guarda a posi��o do in�cio do segundo vetor em $s1
addi $sp,$sp,-20	# Vai para a posi��o final do segundo vetor

#int i - > $s2
# for(i = 0; i < 5; i++)
addi $s2,$zero,0		# Inicializa i
addi $t0,$zero,4
FOR_1:
	slti $t1,$s2,5		# Compara se � menor que 5
	beq $t1,$zero,FIM_FOR_1	# Pula se for maior que 5
#	leia $v0
	addi $v0,$zero,5	# Preparando para ler um inteiro
	syscall			# Faz a chamada ao sistema
#	S0[i] = $v0
	mul $t1,$t0,$s2		# C�lculo de deslocamento			$t1 = 4 * $s2
	add $t1,$t1,$s0		# Soma do endere�o b�sico com o deslocamento	$t1 = $t1 + Endere�o b�sico
	sw $v0,0($t1)		#
	
	addi $s2,$s2,1		# Incrementa i
	j FOR_1			# Volta ao inicio do forr
FIM_FOR_1:

#addi $sp,$sp,40	# Volta para o in�cio do primeiro vetor (adiciona 40 para subir de volta para o in�cio)
add $sp,$zero,$fp	# Mesma coisa por�m mais pr�tico e sem precisar fazer c�lculo de endere�amento	

addi $v0,$zero,10
syscall

# Tarefa, copiar elementos do primeiro vetor para o segundo e imprimir o segundo vetor 
