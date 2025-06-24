# int *ptr
# int i, j, aux
#
# leia n
# aloque array V - com n inteiros
# leia V
#
# $s0 <- n	| $s1 <- V	

addi $v0,$zero,5	# Ler inteiro
syscall
add $s0,$zero,$v0	# Adiciona valor lido em n

addi $v0,$zero,9	# Alocação dinâmica
addi $t0,$zero,4	# Multiplicando 4
mul $t1,$t0,$s0		# Valor em bytes para alocar: n * 4
add $a0,$zero,$t1	# Passando bytes como argumento
syscall			# Chamada ao sistema
add $s1,$zero,$v0	# Guardando posição inicial do vetor alocado

addi $t0,$zero,4	# Multiplicando 4
add $s2,$zero,$zero	# Inicializando i

# $t0 <- 4	| $s2 <- i
INICIO_LEITURA:
	slt $t1,$s2,$s0			# Compara se i é menor que n
	beq $t1,$zero,FIM_LEITURA	# Pula para o fim se for maior
	
	addi $v0,$zero,5		# Ler inteiro
	syscall
	add $t1,$zero,$v0		# Adiciona valor lido em $t1
	
	mul $t2,$s2,$t0			# Calculo de quanto vou ter que pular no vetor
	add $t3,$s1,$t2			# Posição absoluta para colocar o valor lido
	sw $t1, 0($t3)			# Adiciona valor na posição absoluta
	
	addi $s2,$s2,1			# Incrementa i em 1
	j INICIO_LEITURA
FIM_LEITURA:

# for(j = 0; j < n; j++)
#  for(ptr = V; i = 0; i < n; ptr++; i++){
#   if(*ptr > *(ptr + 1)){
#    aux = *ptr
#    *ptr = *(ptr + 1)
#    *(ptr + 1) = aux
#   }
#  }


# $s2 <- j	| $s0 <- n	| $s1 <- V

add $s2,$zero,$zero	# Inicializa j com 0
INICIO_EXTERNO:
	slt $t1, $s2,$s0		# Verifica se j é menor que n
	beq $t1,$zero,FIM_EXTERNO	# Pula para o fim se for maior ou igual
	
	add $s3,$zero,$s1		# Copia endereço do vetor original
	addi $s4,$zero,1		# Inicializa i com 0
	# $s3 <- ptr	| $s4 <- i
	INICIO_INTERNO:
		slt $t1,$s4,$s0			# Verifica se i é menor do que n
		beq $t1,$zero,FIM_INTERNO	# Pula para o fim se for maior ou igual
		
		lw $t0,0($s3)			# Carrega o que está em ptr
		lw $t1,4($s3)			# Carrega o que está em ptr + 1
		
		# $t0 <- *ptr	| $t1 <- *(ptr + 1)
		SE:
			slt $t2,$t1,$t0		# Verifica se ptr+1 é menor que ptr
			beq $t2,$zero,FIM_SE	# Se ptr+1 for maior que ptr então pula para o final
			
			add $t2,$zero,$t0	# Adiciona o valor de *ptr em aux
			
			sw $t1,0($s3)		# *(ptr+1) = *ptr
			sw $t2,4($s3)		# *ptr = *(ptr+1)
		FIM_SE:
		
		addi $s4,$s4,1			# Incrementa i em 1
		addi $s3,$s3,4			# Avança uma posição no vetor
		j INICIO_INTERNO
	FIM_INTERNO:
	
	addi $s2,$s2,1		# Incrementa j em 1
	j INICIO_EXTERNO
FIM_EXTERNO:
	
	
