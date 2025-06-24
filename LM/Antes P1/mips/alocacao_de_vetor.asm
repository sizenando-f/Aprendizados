add $fp,$zero,$sp	# Guarda o $sp original em $fp para restabelecer a pilha

#int S0[5] -> equivalente (20/4 = 5)
addi $sp,$sp,-20	# Vai para a posi��o inicial do segundo vetor (-20 pois o vetor desce no endere�o, 
			# � o do maior para o menor.)
addi $s0,$sp,4		# Guarda a posi��o do in�cio do primeiro vetor em $s0 - 4, posi��o vazia

#int S1[5] -> equivalente
addi $sp,$sp,-20	# Vai para a posi��o final do segundo vetor
addi $s1,$sp,4		# Guarda a posi��o do in�cio do primeiro vetor em $s1 - 4, posi��o vazia

#int i - > $s2
# for(i = 0; i < 5; i++)
addi $s2,$zero,0		# Inicializa i
addi $t0,$zero,4
# Lendo os valores
FOR_1:
	slti $t1,$s2,5		# Compara se � menor que 5
	beq $t1,$zero,FIM_FOR_1	# Pula se for maior que 5
#	leia $v0
	addi $v0,$zero,5	# Preparando para ler um inteiro
	syscall			# Faz a chamada ao sistema
#	S0[i] = $v0
	mul $t1,$t0,$s2		# C�lculo de deslocamento			$t1 = 4 * $s2 (i)
	add $t1,$t1,$s0		# Soma do endere�o b�sico com o deslocamento	$t1 = $t1 + Endere�o b�sico
	sw $v0,0($t1)		#
	
	addi $s2,$s2,1		# Incrementa i
	j FOR_1			# Volta ao inicio do forr
FIM_FOR_1:

# for(i = 0; i < 5; i++) // C�pia
addi $s2,$zero,0		# Inicializa i
addi $t0,$zero,4		# Cria constante para c�lculo de deslocamento
# Copiando
FOR_2:
	slti $t1,$s2,5		# Compara se � menor que 5
	beq $t1,$zero,FIM_FOR_2	# Pula se for maior que 5

	mul $t3,$t0,$s2		# C�lculo de deslocamento			$t1 = 4 * $s2 (i)
	
	add $t1,$t3,$s0		# Soma do endere�o base do primeiro array com o deslocamento	$t1 = $t1 + Endere�o b�sico
	add $t2,$t3,$s1		# Soma do endere�o base do segundo array com o deslocamento
	
	#S1[i] = S0[i]
	lw $t3,0($t1)		# $t3 possui o conteudo de S0[i]
	sw $t3,0($t2)		# � armazenado em S1[i] 
	
	addi $s2,$s2,1		# Incrementa i
	j FOR_2			# Volta ao inicio do forr
FIM_FOR_2:

# Mostra valores
addi $s2,$zero,0		# Inicializa i
addi $t0,$zero,4		# Cria constante para c�lculo de deslocamento
FOR_3:
	slti $t1,$s2,5		# Compara se � menor que 5
	beq $t1,$zero,FIM_FOR_3	# Pula se for maior que 5

	mul $t3,$t0,$s2		# C�lculo de deslocamento			$t1 = 4 * $s2 (i)
	
	add $t2,$t3,$s1		# Soma do endere�o base do segundo array com o deslocamento
	
	lw $a0,0($t2)		# $t2 possui o conteudo de S0[i]
	
	addi $v0,$zero,1	# Configura para mostrar inteiro
	syscall
	
	addi $s2,$s2,1		# Incrementa i
	j FOR_3			# Volta ao inicio do forr
FIM_FOR_3:

#addi $sp,$sp,40	# Volta para o in�cio do primeiro vetor (adiciona 40 para subir de volta para o in�cio)
add $sp,$zero,$fp	# Mesma coisa por�m mais pr�tico e sem precisar fazer c�lculo de endere�amento	

addi $v0,$zero,10
syscall

# Tarefa, copiar elementos do primeiro vetor para o segundo e imprimir o segundo vetor 
