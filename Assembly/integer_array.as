.data
integerArray: .space 16
space: .ascii " "

int1: .word 10
int2: .word 20
int3: .word 30
int4: .word 40

.text

lw $t1, int1
lw $t2, int2
lw $t3, int3
lw $t4, int4

add $t0, $zero, 0

sw $t1, integerArray($t0)
  addi $t0, $t0, 4
sw $t2, integerArray($t0)
  addi $t0, $t0, 4
sw $t3, integerArray($t0)
  addi $t0, $t0, 4
sw $t4, integerArray($t0)

#display

li $t0, 0
li $v0, 1
lw $a0, integerArray($t0)
syscall

li $v0, 4
la $a0, space
syscall

addi $t0, $t0, 4
li $v0, 1
lw $a0, integerArray($t0)
syscall

li $v0, 4
la $a0, space
syscall

addi $t0, $t0, 4
li $v0, 1
lw $a0, integerArray($t0)
syscall

li $v0, 4
la $a0, space
syscall
