.data
text: .asciiz "Enter float: "
newLine: .asciiz "\n"
plus: .asciiz "+"
equals: .asciiz "="

.text 

li $v0, 4
la $a0, text
syscall

li $v0, 6 # when user inputing float
syscall
mov.s $f1, $f0 # save float into f1

li $v0, 4
la $a0, newLine 
syscall

li $v0, 4
la $a0, text
syscall

li $v0, 6 # when user inputing float
syscall
mov.s $f2, $f0 # save float into f2

li $v0, 4
la $a0, newLine 
syscall

# adding
add.s $f3, $f2, $f1

# display
# wanted to write little bit more

mov.s $f12, $f1
li $v0, 2
syscall

li $v0, 4
la $a0, plus 
syscall

mov.s $f12, $f2
li $v0, 2
syscall

li $v0, 4
la $a0, equals 
syscall

mov.s $f12, $f3
li $v0, 2
syscall
