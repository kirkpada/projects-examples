title Floating-Point Comparison 											(floating_comparison.asm)

include Irvine32.inc

.data
;for text
myName BYTE "Programmer's Name: Daniel Kirkpatrick",0ah,0dh,0
progTitle BYTE "Program Name: Floating-Point Comparison",0ah,0dh,0
instruct1 BYTE "Enter two floating-point numbers you would like to compare.",0ah,0dh,0
firstNum BYTE "Enter first number: ",0
secondNum BYTE "Enter second number: ",0
firstGTsec BYTE "The first number is greater than the second number!",0
firstLTsec BYTE "The first number is less than the second number!",0
sameNum BYTE "Both numbers are the same!",0
exitMess BYTE "Thanks for using the program!",0ah,0dh,0


.code
;get two numbers to compare from user
get_num proc
	mov edx, offset instruct1
	call WriteString
	mov edx, offset firstNum			;get first number from user
	call WriteString
	call ReadFloat						;push first number onto the stack ST(0)
	mov edx, offset secondNum			;get second number from user
	call WriteString
	call ReadFloat 						;push second number onto the stack ST(1)
	call Crlf

	ret									;return to main proc

get_num endp

;compare the two numbers to see which is greater
float_comp proc
	fcomi ST(0), ST(1)					;compares ST(0) and ST(1)
	ja lesser							;jmp if ST(0) < ST(1)
	jb greater							;jmp if ST(0) > ST(1)
	je same 							;jmp if ST(0) == ST(1)


	greater:
		mov edx, offset firstGTsec
		call WriteString
		call Crlf
		jmp ending

	lesser:
		mov edx, offset firstLTsec
		call WriteString
		call Crlf
		jmp ending

	same:
		mov edx, offset sameNum
		call WriteString
		call Crlf
		jmp ending

	ending:
		ret

float_comp endp

;main procedure (drives the program)
main proc
	FINIT								;initialize FPU

	;programmer name and title of program
	mov edx, offset myName
	call WriteString
	mov edx, offset progTitle
	call WriteString
	call Crlf

	;make call to get user input
	call get_num

	;make call to comparison proc
	call float_comp

	;exit message
	call Crlf
	mov edx, offset exitMess
	call WriteString
	call Crlf

main endp

exit
end main