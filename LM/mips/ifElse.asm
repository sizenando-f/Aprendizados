# avalia��o da express�o pula se for VERDADEIRO mas usamos para
# situa��o que desejamos ser FALSA (salta pro Else se exisitir, sen�o para as inst. ap�s o If)
# J <label> - salta para o endere�o (label)
#
# slt $t0,$s1,$s0
#
# beq $t0,$zero,ELSE
# addi $v0,$zero,1	- 1 = exibir inteiro
# add $a0,$zero,$s0
# syscall
# j FIM_ELSE
#
# ELSE:
# addi $v0,$zero,1	- 1 = exibir inteiro
# add $a0,$zero,$s1
# syscall
# FIM_ELSE:
# addi $v0,$zero,10	- 10 = exit
# syscall
#