# Laços
#while(<exp>){	// branch
#	<corpo while>
#}		// jump
#inst apos while

### WHILE
# int i = 0;	// i -> $s0
# while(i < 5){	
# <corpo while>
# i++;
# }
# inst após while

addi $s0,$zero,0	# adiciona 0 ao s0
WHILE:
slti $t0,$s0,5		# verifica se s0 é menor que 5, se sim guarda 0 em t0, senão guarda 1
beq $t0,$zero,FIM_WHILE # Pula para o fim do while se t0 for maior que 5
# Corpo do while
addi $s0,$s0,1		# incrementa s0
j WHILE
FIM_WHILE:

### DO WHILE
# int i = 0;
# do{	
# <corpo while>
# i++;
# } while(i < 5);
#

addi $s0,$zero,0
DO:
# corpo do DO
addi $s0,$s0,1
slti $t0,$s0,5
bne $t0,$zero,DO

### FOR
# for(<exp ini>; <exp teste>; <exp passo>){	
# <corpo for>
# };
# Primeiro a expressão de inicialização, depois testa, se verdadeiro executa, depois faz o passo e repete o teste

# int i = 0;
# for(i = 0; i < 5; i++){	
# <corpo for>
# };

addi $s0,$zero,0
FOR:
slti $t0,$s0,5
beq $t0,$zero,FIM_FOR
# <corpo for>
j FOR
FIM_FOR:











