# x = s0 | y = s1 | z = s2 | w = s3
#addi $s0,$zero,1
#addi $s1,$zero,1
#addi $s2,$zero,1
#addi $s3,$zero,1

# ler x, y, z, w
addi $v0,$zero,5 	# Grava código 5 (leitura de inteiros)
syscall			# Chama o syscall para verificar o $v0
add $s0,$zero,$v0	# Salva na variável X

# ler y
addi $v0,$zero,5
syscall
add $s1,$zero,$v0	# Salva na variável Y

# ler z
addi $v0,$zero,5
syscall
add $s2,$zero,$v0	# Salva na variável Z

# ler w
addi $v0,$zero,5
syscall
add $s3,$zero,$v0 	# Salva na variável W

add $t0,$s0,$s1 # t0 = x + y
sub $t0,$t0,$s2 # t0 = (x + y) - z
sub $s0,$t0,$s3 # x = (x + y - z) - w

# escrever x
addi $v0,$zero,1	# Define código 1 para syscall (printar inteiro) 
add $a0,$zero,$s0	# Adiciona o número que será exibido
syscall