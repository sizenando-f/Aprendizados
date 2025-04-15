# leia a,b,c,b
addi $v0,$zero,5
syscall
add $s0,$zero,$v0

addi $v0,$zero,5
syscall
add $s1,$zero,$v0

addi $v0,$zero,5
syscall
add $s2,$zero,$v0

addi $v0,$zero,5
syscall
add $s3,$zero,$v0

# a = (a | b) + (b < c) + (b & d)
or $t0,$s0,$s1
slt $t1,$s1,$s2
and $t2,$s1,$s3

add $t0,$t0,$t1
add $s0,$t0,$t2

# imprima a, b, c, d
addi $v0,$zero,1
add $a0,$zero,$s0
syscall

addi $v0,$zero,10 # código para saída de sistema
syscall
