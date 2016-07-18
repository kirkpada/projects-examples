TITLE MASM Template						(main.asm)

INCLUDE Irvine32.inc
.data
;For Constants
MAXLENGTH = 20
MAXVALUE = 101
MINVALUE = -1
;For Strings
progName BYTE "Name: Daniel Kirkpatrick",0dh,0ah,0
progTitle BYTE "Title: Average Calculator",0dh,0ah,0
userName BYTE "Please enter your name: ",0
greeting1 BYTE "Hello, ",0
greeting2 BYTE "!",0dh,0ah,0
greeting3 BYTE "Welcome to the Average Calculator!",0dh,0ah,0
userNameInput BYTE MAXLENGTH+1 DUP(?)
instruct1 BYTE "Please enter a number between 0 and 100: ",0dh,0ah,0
instruct2 BYTE "To exit program and get average enter a NEGATIVE number!(Example: -3): ",0
sumInstruct1 BYTE "Enter another number between 0 and 100.",0dh,0ah,0
sumInstruct2 BYTE "To exit program and get average enter a NEGATIVE number!(Example: -3): ",0
errorGreater1 BYTE "You entered a number to big.",0dh,0ah,0
errorGreater2 BYTE "Enter another number between 0-100: ",0
errorLesser1 BYTE "You entered a negative number!",0dh,0ah,0
errorLesser2 BYTE "Exiting program! Bye, ",0
sumCheck BYTE "The sum after adding is: ",0
rounds1 BYTE "You have entered ",0
rounds2 BYTE " numbers.",0
fCount BYTE "Number of non-negative numbers entered: ",0
fSum BYTE "Sum of all non-negative numbers is: ",0
fAvg BYTE "The average rounded to the nearest integer is: ",0
;For Numbers
inputNum DWORD ?
sum DWORD ?
counter DWORD ?
finalCount DWORD ?
finalSum DWORD ?
average1 DWORD ?
average2 DWORD ?



.code
main PROC
	;Output programmer name and title of program
	mov edx, OFFSET progName
	call WriteString
	mov edx, OFFSET progTitle
	call WriteString
	call Crlf

	;Get user's name and greet user
	mov edx, OFFSET userName
	call WriteString
	mov edx, OFFSET userNameInput
	mov ecx, MAXLENGTH
	call ReadString
	call Crlf
	mov edx, OFFSET greeting1
	call WriteString
	mov edx, OFFSET userNameInput
	call WriteString
	mov edx, OFFSET greeting2
	call WriteString
	call Crlf
	mov edx, OFFSET greeting3
	call WriteString
	call Crlf
	mov edx, OFFSET instruct1
	call WriteString
	mov edx, OFFSET instruct2
	call WriteString
	call ReadInt
	mov inputNum, eax
	jmp numCheck
	
	;used to check if number is within correct number range
	;error handling section
	numCheck:
		mov eax, inputNum
		cmp eax, MAXVALUE
		jnl greater 			;jumps if value is greater than 100
		cmp eax, MINVALUE
		jng lesser 			;jumps if value is less than 0
		jmp correctValue 	;jumps if value is correct and program proceeds
	greater:
	;if number is greater than 100 it will ask for a new input
		call Crlf
		call Crlf
		mov edx, OFFSET errorGreater1
		call WriteString
		mov edx, OFFSET errorGreater2
		call WriteString
		call ReadInt
		mov inputNum, eax
		jmp numCheck
	lesser:
	;if number is negative it will calculate average and exit program
		mov edx, 0
		mov eax, sum
		mov finalSum, eax
		mov eax, counter
		mov finalCount, eax
		mov eax, finalSum
		mov ebx, finalCount
		div ebx
		mov average1, eax
		mov average2, edx
		correction:
			mov eax, average2
			cmp eax, 5
			jge fix
			jl continue
			fix:
				mov eax, average1
				add eax, 1
				mov average1, eax
			continue:

			jmp finalInformation

	correctValue:
	;if number is in correct range it will add to sum
		mov inputNum, eax
		mov eax, sum
		add eax, inputNum
		mov sum, eax
		mov edx, OFFSET sumCheck
		call WriteString
		call WriteInt
		call Crlf
		jmp driver

	driver:
		numCounter:
		;counts how many numbers are entered
			mov ecx, 0
			mov ecx, counter
			inc ecx
			mov counter, ecx
			mov edx, OFFSET rounds1
			call WriteString
			mov eax, counter
			call WriteInt
			mov edx, OFFSET rounds2
			call WriteString
			call Crlf
			call Crlf
		nextInput:
		;gets the next input from the user
			mov eax, sum
			mov edx, OFFSET sumInstruct1
			call WriteString
			mov edx, OFFSET sumInstruct2
			call WriteString
			call ReadInt
			mov inputNum, eax
			jmp numCheck

	finalInformation:
	;prints out number of numbers entered, sum and average
		call Crlf
		call Crlf
		call Crlf
		mov edx, OFFSET errorLesser1
		call WriteString
		call Crlf
		mov edx, OFFSET fCount
		mov eax, finalCount
		call WriteString
		call WriteInt
		call Crlf
		mov edx, OFFSET fSum
		mov eax, finalSum
		call WriteString
		call WriteInt
		call Crlf
		mov edx, OFFSET fAvg
		mov eax, average1
		call WriteString
		call WriteInt
		call Crlf
		jmp progExit

	progExit:
	;parting message and program exit
		call Crlf
		call Crlf
		mov edx, OFFSET errorLesser2
		call WriteString
		mov edx,OFFSET userNameInput
		call WriteString
		call Crlf
		call Crlf

	exit
main ENDP

END main