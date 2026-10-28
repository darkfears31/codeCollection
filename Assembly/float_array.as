.data
whileArray: .space 16
newLine: .ascii "\n"

val0: .float 3.14
val1: .float 2.71
val2: .float 1.0132
val3: .float 3.1254

.text
lwc1 $f0, val0
lwc1 $f1, val1
lwc1 $f2, val2
lwc1 $f3, val3

add $t0, $zero, 0

swc1 $f0, whileArray($t0)
	addi $t0, $t0, 4 # $t0 = 4
swc1 $f1, whileArray($t0)
	addi $t0, $t0, 4 # $t0 = 8
swc1 $f2, whileArray($t0)
	addi $t0, $t0, 4 # $t0 = 8
swc1 $f3, whileArray($t0)

addi $t0, $zero, 0

while:
	beq $t0, 16, stop
	
	lwc1 $f12, whileArray($t0)
	li $v0, 2
	syscall
	
	li $v0, 4
	la $a0, newLine
	syscall
	
	addi $t0, $t0, 4	
	j while 

stop:
li $v0, 10
syscall
