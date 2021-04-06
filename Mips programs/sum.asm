.data
msg1: .asciiz "Enter a number: "
msg2: .asciiz "Half of number: "

.text
	li $v0, 4
	la $a0, msg1
	syscall
	
	li $v0, 5
	syscall
	
	move $s0, $v0
	div $s0, $s0, 2
	
	li $v0, 4
	la $a0, msg2
	syscall
	
	li $v0, 1
	move $a0, $s0
	syscall
	
	li $v0, 10
	syscall
	