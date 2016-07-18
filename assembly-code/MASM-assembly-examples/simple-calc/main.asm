TITLE MASM Template						(main.asm)

INCLUDE Irvine32.inc
.data
myName BYTE "Name: Daniel Kirkpatrick",0dh,0ah,0
progTitle BYTE "Title: Assignment 1: Simple arithmatic calculator",0dh,0ah,0
progInstruct BYTE"Instruction: This program will ask for two integer numbers. **NOTE: Please make sure they are both positive integers!!** After you pick the numbers the program will add, sub, mul, div and give the remainder. Enjoy!",0dh,0ah,0
firstNum BYTE "Enter first number please!",0dh,0ah,0
secNum BYTE "Enter second number please!",0dh,0ah,0
exitMessage BYTE "All calculations complete! Bye! :D",0dh,0ah,0
num_1 DWORD ?
num_2 DWORD ?
quot DWORD ?
remind DWORD ?
sum BYTE "Sum is: ",0
difference BYTE "Difference is: ",0
product BYTE "Product is: ",0
quotient BYTE "Quotient is: ",0
remainder BYTE "Remainder is: ",0

.code
main PROC
	call Clrscr
	
	; Output name to screen
	mov	edx, OFFSET myName
	call WriteString

	; Output program title to screen
	mov edx, OFFSET progTitle
	call WriteString
	call Crlf

	; Output program instructions to screen
	mov edx, OFFSET progInstruct
	call WriteString
	call Crlf
	
	; Gets first number from user
	mov edx, OFFSET firstNum
	call WriteString
	call ReadInt
	mov num_1, eax

	; Gets second number from user
	mov edx, OFFSET secNum
	call WriteString
	call ReadInt
	mov num_2, eax

	; addition section
	mov eax, num_1		;eax = num_1
	add eax, num_2		;eax + num_2 stored in edx
	mov edx, OFFSET sum
	call WriteString
	call WriteInt
	call Crlf

	; subtraction section
	mov eax, num_1		;eax = num_1
	sub eax, num_2		;eax - num_2 stored in edx
	mov edx, OFFSET difference
	call WriteString
	call WriteInt
	call Crlf

	; multiplication section
	mov eax, num_1		;eax = num_1
	mov ebx, num_2		;ebx = num_2
	mul ebx			;eax*ebx stored in edx
	mov edx, OFFSET product
	call WriteString
	call WriteInt
	call Crlf

	; division and remainder section
	mov edx, 0		;edx = 0
	mov eax, num_1		;eax = num_1
	mov ebx, num_2		;ebx = num_2
	div ebx			;eax/ebx stored in eax(quotient) and edx(remainder)
	mov quot, eax

	; print quotient
	mov remind, edx
	mov edx, OFFSET quotient
	call WriteString
	call WriteInt
	call Crlf

	; print remainder
	mov eax, remind
	mov edx, OFFSET remainder
	call WriteString
	call WriteInt
	call Crlf

	; Output exit message
	mov	edx, OFFSET exitMessage
	call WriteString
	call Crlf

	exit
main ENDP

END main