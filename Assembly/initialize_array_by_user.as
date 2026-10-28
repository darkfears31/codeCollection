.data 
array: .space 16
text: .asciiz "Enter Integer to write in array: "
displayText: .asciiz "Displaying array: "
newLine: .ascii "\n"
space: .ascii " "

.text

li $t0, 0

li $v0, 4
la $a0, text
syscall

li $v0, 5
syscall
sw $v0, array($t0)
addi $t0, $t0, 4

li $v0, 4
la $a0, newLine 
syscall

li $v0, 4
la $a0, text
syscall

li $v0, 5
syscall
sw $v0, array($t0)
addi $t0, $t0, 4

li $v0, 4
la $a0, newLine 
syscall

li $v0, 4
la $a0, text
syscall

li $v0, 5
syscall
sw $v0, array($t0)

li $v0, 4
la $a0, newLine 
syscall

#display
li $v0, 4
la $a0, displayText 
syscall

li $v0, 4
la $a0, newLine 
syscall

li $t0, 0
lw $a0, array($t0)
li $v0, 1
syscall

li $v0, 4
la $a0, space 
syscall

addi $t0, $t0, 4
lw $a0, array($t0)
li $v0, 1
syscall

li $v0, 4
la $a0, space 
syscall

addi $t0, $t0, 4
lw $a0, array($t0)
li $v0, 1
syscall
