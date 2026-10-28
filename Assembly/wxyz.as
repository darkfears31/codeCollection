# w=x+y-z
.data
x: .word 10
y: .word 5
z: .word 8

message: .asciiz "Result: "

.text 

lw $t0 ,x
lw $t1 ,y
lw $t2 ,z

add $t3, $t0, $t1
sub $t4, $t3, $t2

li $v0, 4
la $a0, message
syscall

move $a0, $t4
li $v0, 1
syscall



