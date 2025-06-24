# S0[x], $s2 <- x | S0 <- $s0
addi $v0,$zero,5	# Para ler inteiro
syscall
add $s2,$zero,$v0	# Guarda o valor lido em $s2

mul $t1,$s2,4		# Guarda o tamanho do vetor multiplicado por 4
addi $v0,$zero,9	# Diz que é alocação dinâmica
add $a0,$zero,$t1	# Quantidade de byte que alocado
syscall
add $s0,$zero,$v0	# Guarda o endereço base em $s0

addi $t0,$zero,4	# $t1 agora guarda o multiplicando 4
add $s1,$zero,$zero	# Inicializia $s1 com 0, ele será o i do iterador

INICIO_LACO:
	slt $t1,$s1,$s2		# Compara se i é menor que o tamanho do vetor alocado (x)
	beq $t1,$zero,FIM_LACO	# Se for maior, pula pro final do laço
	
	add $t1,$zero,$s0	# Carrega o endereço base em $t1
	mul $t2,$s1,$t0		# Faz o cálculo de deslocamento com i * 4
	add $t1,$t2,$s0		# Aplico o deslocamento a partir do endereço base
	
	add $t2,$zero,$s1	# Armazeno o valor de i em $t2
	sw $t2,0($t1)		# Coloco o valor i na posição adequada
	
	addi $s1,$s1,1		# Incrementa i em 1
	j INICIO_LACO
FIM_LACO: