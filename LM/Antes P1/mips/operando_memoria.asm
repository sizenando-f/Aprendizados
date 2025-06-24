# Operando com mem�ria
# -> instru��o para grava��o na mem�ria
# sw reg1, offset(reg2)
#	-> reg1 - palavra a ser gravado
#	-> reg2 - endere�o base na MEM
#	-> offset - deslocamento a partir de reg2 (dado em n�mero de bytes e sinalizado de 16 bits)
# 			MEM[reg2 + offset] <- reg1 | reg1 vai ser gravado emreg2 + offset = endere�o 
#			que tem que ser m�ltiplo de 4
#
# sh - store half word | reg2 + offset tem que ser m�ltiplo de 2
# sb - store byte
# sw - store word
#
#	pilha come�a no �ltimo endere�o e vai diminuindo, "cresce ao contr�rio (para baixo)"
#	sp - cont�m o primeiro endere�o livre do programa, de cima para baixo, primeiro byte da palavra
#	0FFF primeira metade, +2 offset para segunda metade
#

addi $s0,$zero,0xFFF # = 0xffffffff

#Guardando palavras
#sw $s0,0($sp)
#sh $s0,0($sp)	# 0x00000fff | 0 no offset pois sp come�a do �ltimo para o come�o
#sh $s0,2($sp)	# Avan�ou mais 2 bytes | 0x0fff0fff
#sw $s0,-0x20($sp)	# 0x00000fff no registrador anterior
#sw $s0,1($sp)	# Vai dar erro pois o offset n�o � m�ltiplo de 4
#sh $s0,1($sp)	# Vai dar erro pois o offset n�o � m�ltiplo de 2
#sb $s0,1($sp)	# Vai pegar o byte menos significativo (o �ltimo byte, 'F' no caso)

sb $s0,0($sp)
sb $s0,1($sp)
sb $s0,2($sp)
sb $s0,3($sp)

# Carregando palavras
# lw reg1, offset(reg2) # Grava em reg1
# Se gravar meia palavra, vai gravar nos bytes menos significativos

lw $s0,0($sp)	# Carrega o que est� apontado por $sp no registrador $s0

addi $v0,$zero,10
syscall