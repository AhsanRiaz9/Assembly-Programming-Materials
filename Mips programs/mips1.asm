.data
okay: .asciiz "Ahsan Riaz"
.text
main:
	li $v0, 4
	la $a0, okay
	syscall
	
	li $v0, 10
	syscall
	
	  