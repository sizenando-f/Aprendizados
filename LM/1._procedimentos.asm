# Procedimentos
# a0, a1, a2, a3 -> Passagem de parâmetros
# Passa numa pilha se não for suficiente 
# v0, v1 -> Retorno do procedimento
# jal -> jump and link -> salta para o label e guarda pc + 4 em ra 
# jr -> jump register -> pula para endereço guardado em um registrador

# s0...s7 -> Registradores temporários SALVOS

# Procedimento folha (ñ faz chamada de outro procedimento)
# receita:
# 1. Armazenar parâmetros
# 2. jal
# 3. Executa o procedimento
# 4. Guardar retorno
# 5. jr
# 6. Recuperar retorno

# Ler A e B: A -> $s0 | B -> $s1

addi $v0,$zero,5
syscall
add $s0,$zero,$v0

addi $v0,$zero,5
syscall
add $s1,$zero,$v0

# C = soma(a,b): C -> $s2
add $a0,$zero,$s0
add $a1,$zero,$s1
jal PROC_SOMA
add $s2,$zero,$v0

# Impressão do C
addi $v0,$zero,1
add $a0,$zero,$s2
syscall

# return 0;
addi $v0,$zero,10
syscall

PROC_SOMA:
#int soma(int x, int y){
	add $v0,$a0,$a1		# soma os dois argumentos
	jr $ra			# ra guarda pc + 4 do endereço de onde foi chamado o jal
# 	return x + y;
#}








