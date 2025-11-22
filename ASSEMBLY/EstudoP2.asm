.data
	VP:	.word 2,3,5,2,1,6
.text
MAIN:
	lui $s0, 0x1001			# $s0 <- Endereço base do vetor
	addi $s1, $zero, 6		# $s1 <- N elementos
	
	add $a0, $zero, $s0
	addi $a1, $zero, 0
	addi $t0, $s1,-1
	add $a2, $zero, $t0
	
	jal PROC_MERGESORT
	
	j FIM
	
PROC_MERGE:
    add $fp, $zero, $sp   # 1. Ancorar

    # 2. Calcular o tamanho em bytes do temp...
    #    ... SEU CÓDIGO AQUI ...
	sub $t0, $a3, $a1
	addi $t0, $t0, 1
	sll $t0, $t0, 2		# Tamanho do vetor em bytes
	
	
    # 3. Alocar espaço total (regs + temp)...
    #    ... SEU CÓDIGO AQUI ...
    sub $sp, $sp, $t0		# Tamanho do vetor
    addi $sp, $sp, -40	# Quantidade de registradores
    
    # Salva registradores
    sw $fp, 0($fp)		# Ancora
    sw $ra, -4($fp)		# Retoro
    sw $s0, -8($fp)		# base de vetor
    sw $s1, -12($fp)	# indice inicio
    sw $s2, -16($fp)	# indice meio
    sw $s3, -20($fp)	# indice fim
    sw $s4, -24($fp)	# indice i
    sw $s5, -28($fp)	# indice j
    sw $s6, -32($fp)	# indice k
    sw $s7, -36($fp)	# base do vetor temp
    
    add $s0, $zero, $a0
    add $s1, $zero, $a1
    add $s2, $zero, $a2
    add $s3, $zero, $a3
    
    add $s4, $zero, $s1
    add $s5, $zero, $s2
    addi $s5, $s5, 1
    
    add $s6, $zero, $zero
    addi $s7, $fp, -40

PROC_MERGESORT:
    # --- Prólogo ---
    # 1. Salvar $fp, $ra, e todos os $s que usaremos
    #    (Precisaremos de $s0=base, $s1=inicio, $s2=fim, $s3=meio)
    #    ... SEU CÓDIGO AQUI ...
    add $fp, $zero, $sp
    addi $sp, $sp, -24
    sw $fp, 0($fp)
    sw $ra, -4($fp)
    sw $s0, -8($fp)
    sw $s1, -12($fp)
    sw $s2, -16($fp)
    sw $s3, -20($fp)
    

    # 2. Copiar argumentos para registradores $s
    #    $s0 <- $a0 (base)
    #    $s1 <- $a1 (inicio)
    #    $s2 <- $a2 (fim)
    #    ... SEU CÓDIGO AQUI ...
    add $s0, $zero, $a0
    add $s1, $zero, $a1
    add $s2, $zero, $a2

    # --- Caso Base ---
    # 3. Verificar se inicio >= fim.
    #    Se sim, pular direto para o FIM_MERGESORT.
    #    (Dica: use slt e bne/beq)
    #    ... SEU CÓDIGO AQUI ...
    slt $t0, $s1, $s2
    beq $t0, $zero, FIM_MERGESORT

PASSO_RECURSIVO:
    # --- Dividir ---
    # 4. Calcular meio = (inicio + fim) / 2
    #    (Dica: add e srl)
    #    $s3 <- meio
    #    ... SEU CÓDIGO AQUI ...
    add $t0, $s1, $s2
    srl $s3, $t0, 1

    # --- Conquistar (Chamadas Recursivas) ---
    # 5. Primeira chamada: mergeSort(vetor, inicio, meio)
    #    Preparar $a0, $a1, $a2 e fazer 'jal PROC_MERGESORT'
    #    ... SEU CÓDIGO AQUI ...
    add $a0, $zero, $s0
    add $a1, $zero, $s1
    add $a2, $zero, $s3
    jal PROC_MERGESORT

    # 6. Segunda chamada: mergeSort(vetor, meio + 1, fim)
    #    Preparar $a0, $a1, $a2 e fazer 'jal PROC_MERGESORT'
    #    ... SEU CÓDIGO AQUI ...
    add $a0, $zero, $s0
    addi $t0, $s3, 1
    add $a1, $zero, $t0
    add $a2, $zero, $s2
    jal PROC_MERGESORT

    # --- Combinar (Chamar o 'merge') ---
    # 7. Chamar uma função separada PROC_MERGE
    #    Vamos passar para ela: merge(vetor, inicio, meio, fim)
    #    (Vamos precisar de $a0, $a1, $a2, $a3)
    #    ... SEU CÓDIGO AQUI ...
    #    jal PROC_MERGE
    add $a0, $zero, $s0
    add $a1, $zero, $s1
    add $a2, $zero, $s3
    add $a3, $zero, $s2
    jal PROC_MERGE
    

FIM_MERGESORT:
    # --- Epílogo ---
    # 8. Restaurar todos os registradores da pilha
    #    ... SEU CÓDIGO AQUI ...
    lw $fp, 0($fp)
    lw $ra, -4($fp)
    lw $s0, -8($fp)
    lw $s1, -12($fp)
    lw $s2, -16($fp)
    lw $s3, -20($fp)
    
    # 9. Limpar a pilha (restaurar $sp) e retornar
    #    ... SEU CÓDIGO AQUI ...
    #    jr $ra
    add $sp, $zero, $fp
    jr $ra


FIM:
	addi $v0, $zero, 10
	syscall





















#.data
#VP: .word 2,3,1,5,7   # Nosso vetor de 5 elementos
#.text
#main:
    # Carrega o endereço base de VP (0x10010000)
    #lui $a0, 0x1001
    #addi $a1, $zero, 5		# Número de elementos
    #jal PROC_SOMA_VETOR
    #add $a0, $zero, $v0
	#addi $v0, $zero,1
	#syscall
	#addi $v0, $zero,10
	#syscall
#PROC_SOMA_VETOR:
	# Salva ponteiro pra pilha
	#add $fp, $zero, $sp
	# Aloca espaço na pilha
	#addi $sp, $sp, -16
	#sw $s0, 0($fp)
	#sw $s1, -4($fp)
	#sw $s2, -8($fp)
	#sw $s3, -12($fp)
	# Registradores sugeridos:
    # $s1 = SOMA (comece com 0)
    #add $s1, $zero, $zero
    # $s2 = i
    #add $s2, $zero, $zero
    #add $s0, $zero, $a0
    #add $s3, $zero, $a1
#INICIO_LOOP:
	# i < 5?
	#slt $t0, $s2, $s3
	# Se for maior ou igual então sai do loop
	#beq $t0, $zero, FIM_LOOP
	# i * 4
	#sll $t1, $s2, 2
	# endereço base + i * 4
	#add $t2, $s0, $t1
	# Carrega do endereço calculado
	#lw $t3, 0($t2)
	# Soma += valor
	#add $s1, $s1, $t3
	# i++
	#addi $s2, $s2, 1
	#j INICIO_LOOP
#FIM_LOOP:
	#add $v0, $zero, $s1
	# Restaura $s usados
	#lw $s0, 0($fp)
	#lw $s1, -4($fp)
	#lw $s2, -8($fp)
	#lw $s3, -12($fp)
	# Restaura ponteiro da pilha
	#add $sp, $zero, $fp
	#jr $ra

	# Lê float
	#addi $v0, $zero, 6
	#syscall
	# Salva o float lido
	#mov.s $f2, $f0			# $f2 <- N
	#addi $t0, $zero, 18
	#mtc1 $t0, $f3
	#cvt.s.w $f3, $f3
	#addi $t0, $zero, 10
	#mtc1 $t0, $f4
	#cvt.s.w $f4, $f4
	#div.s $f3, $f3, $f4		# $f3 <- 1.8
	#addi $t0, $zero, 32
	#mtc1 $t0, $f4
	#cvt.s.w $f4, $f4		# $f4 <- 32	
	#mul.s $f5, $f2, $f3		# $f5 <- C * 1.8
	#add.s $f6, $f4, $f5		# $f6 (C*1.8) + 32
	#addi $v0, $zero, 2		# Printa float
	#mov.s $f12, $f6
	#syscall 
	#addi $v0, $zero, 10
	#syscall

#PROC_SOMA_REC:
	#slti $t0, $a0, 1	# Verifica se é menor que 1
	#beq $t0, $zero, PROC_SOMA_REC_FIM	# Se for maior ou igual a 1, ele pula pro próximo passo
	#addi $v0, $zero, 0	# Retorno base 0
	#jr $ra 	# Retorna para onde foi chamado
#PROC_SOMA_REC_FIM:
	#add $fp, $zero, $sp		# Salva estado atual da pilha
	#addi $sp, $sp, -16
	#sw $fp, 0($sp)		# Salva ponteiro atual
	#sw $ra, -4($sp)		# Salva endereço para retornar
	#sw $a0, -8($sp)		# Salva valor atual para somar depois
	#sw $s0, -12($sp)	# Salva acumulador
	#addi $a0, $a0, -1	# Decrementa 1 em N
	#jal PROC_SOMA_REC
	#lw $fp, 0($sp)		# Pega de volta o ponteiro da pilha da chamada respectiva
	#lw $ra, -4($sp)		# Pega de volta o endereço de retorno atual
	#lw $a0,	-8($sp)	# Pega valor atual para somar
	#add $s0, $a0, $v0	# Soma no acumulador o valor atual + a soma obtida das chamadas anteriores
	#add $v0, $zero, $s0	# Define retorno
	#lw $s0, -12($sp)	# Restaura $s0 armazenado (pra que se?)
	#add $sp, $zero, $fp
	#jr $ra
#FIM:
	#addi $v0, $zero, 10
	#syscall

	# Le um inteiro
	#addi $v0, $zero, 5
	#syscall
	#add $a0, $v0, $zero
	# Le outro inteiro
	#addi $v0, $zero, 5
	#syscall
	#add $a1, $v0, $zero
	# Chama função
	#jal PROC_MEDIA
	# Printa na tela
	#add $a0, $v0, $zero
	#addi $v0, $zero, 1
	#syscall
	# Encerra o programa
	#j FIM
#PROC_MEDIA:
	# Salva estado atual da pilha
	#add $fp, $zero, $sp
	#addi $sp, $sp, -4
	# Salva o endereço de retorno
	#sw $ra, 0($sp)
	# $a0 e $a1 já contém os dois inteiros
	#jal PROC_SOMA
	# Preapara o divisor
	#addi $t0, $zero, 2
	#div $v0, $t0		# soma / 2
	# Resultado em da divisão
	#mflo $v0
	# Recarrega endereço de retorno
	#lw $ra, 0($sp)
	# Restarua pilha
	#add $sp, $zero, $fp
	# Pula de volta
	#jr $ra	
#PROC_SOMA:
	# Realiza a soma
	#add $v0, $a0, $a1
	# Volta pra onde foi chamado
	#jr $ra


	#add $fp, $zero, $sp
	#addi $sp, $sp, -8
	#sw $s0, 0($sp)
	#sw $s1, -4($sp)

	#addi $sp, $sp, -4		# Abre espaço para um inteiro
	#sw $s0, 0($sp)			# Empilha o que está em $s0

	# Lê inteiro
	#addi $v0, $zero, 5
	#syscall
	# Move para lugar seguro
	#add $s0, $v0, $zero
	# Imprime inteiro
	#add $a0, $s0, $zero
	#addi $v0, $zero, 1
	#syscall
	# Termina programa
	#addi $v0, $zero, 10
	#syscall
