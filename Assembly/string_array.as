.data
myStrings: .space 12

str1: .asciiz "Giorgi"
str2: .asciiz "Labadze"
str3: .asciiz "TSU"

.text
addi $t0, $zero, 0

la $t1, str1
la $t2, str2
la $t3, str3 

sw $t1, myStrings($t0) 
    addi $t0, $t0, 4 
sw $t2, myStrings($t0)
    addi $t0, $t0, 4 
sw $t3, myStrings($t0)
 
lw $a0, myStrings($t0) 
li $v0, 4
syscall
