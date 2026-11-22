.data
message1: .asciiz "Giorgi Labadze.\n"
message2: .asciiz "TSU\n"

.text
jal printMessage1
jal printMessage2
li $v0, 10
syscall

printMessage1:
li $v0, 4
la $a0, message1
syscall

jr $ra

printMessage2:
li $v0, 4
la $a0, message2
syscall

jr $ra
