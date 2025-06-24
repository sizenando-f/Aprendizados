# int *ptr
# int i, soma, cont_par, cont_impar;
#
# leia n
# aloque array V - com n inteiros
# leia V

# $s0 <- n	| $s1 <- V

addi $v0,$zero,5	# Leitura de inteiro
syscall			# Chamada ao sistema
add $s0,$zero,$v0	# N vai para $s0

addi $t0,$zero,4	# Multiplicando 4
mul $t1,$t0,$s0		# $t1 = n * 4

addi $v0,$zero,9	# Alocação dinâmica
add $a0,$zero,$t1	# Aloca quantidade de bytes calculada
syscall			# Chamada ao sistema
add $s1,$zero,$v0	# Guarda posição alocada em $s1

addi $t0,$zero,4	# Multiplicando 4
add $s2,$zero,$zero	# Inicia i com 0
INICIO_LEITURA:
	slt $t1,$s2,$s0			# Verifica se i é menor que n
	beq $t1,$zero,FIM_LEITURA	# Pula se for maior
	
	mul $t1,$t0,$s2			# Multiplica i por 4
	add $t2,$s1,$t1			# Calcula posição absoluta em $t2
	
	addi $v0,$zero,5		# Leitura de x
	syscall
	sw $v0,0($t2)			# Coloca valor na posição adequada

	addi $s2,$s2,1			# Incrementa i em 1
	j INICIO_LEITURA
FIM_LEITURA:

# cont_par = cont_impar = soma = 0
# for(ptr = V, i = 0; i < n; ptr++, i++){
#  if(*ptr % 2){
#   cont_impar++;
#  } else {
#   cont_par++;
#  }
#  soma += *ptr;
# }
#
# escreva soma, cont_impar e cont_par

# $s0 <- n	| $s1 <- V	| $s2 <- cont_par	| $s3 <- cont_impar	| $s4 <- soma
# $s5 <- ptr

add $s2,$zero,$zero	# Inicializa cont_par
add $s4,$zero,$zero	# Inicializa soma com 0
add $s5,$zero,$s1	# Copia V para ptr
add $s6,$zero,$zero	# Inicializa i com 0
addi $s7,$zero,2	# Dividendo 2
INI_COMP:
	slt $t0,$s6,$s0			# Verifica se i é menor que n
	beq $t0,$zero,FIM_COMP		# Pula se for maior
	
	lw $t1,0($s5)			# Carrega em t1 o valor que está em ptr
	add $s4,$s4,$t1			# Soma o valor lido no acumulador
	div $t1,$s7			# Divide o valor lido por 2
	mfhi $t1			# Pega o resto e guarda em t1
	
	beq $t1,$zero,ADICIONA_PAR
	addi $s3,$s3,1			# Incrementa cont_impar em 1
	j FIM_ADICIONA
	ADICIONA_PAR:
		addi $s2,$s2,1			# Incrementa cont_par em 1
	FIM_ADICIONA:
	
	addi $s5,$s5,4			# Incrementa o ponteiro
	addi $s6,$s6,1			# Incrementa i em 1
	j INI_COMP
FIM_COMP:

addi $v0,$zero,1	# Printa inteiro
add $a0,$zero,$s4	# Coloca o valor de soma
syscall			# Chamada ao sistema

addi $v0,$zero,11	# Para printar caractere
addi $a0,$zero,32	# Espaco em ASCII
syscall

addi $v0,$zero,1	# Printa inteiro
add $a0,$zero,$s3	# Coloca o valor de soma
syscall			# Chamada ao sistema

addi $v0,$zero,11	# Para printar caractere
addi $a0,$zero,32	# Espaco em ASCII
syscall

addi $v0,$zero,1	# Printa inteiro
add $a0,$zero,$s2	# Coloca o valor de soma
syscall			# Chamada ao sistema


