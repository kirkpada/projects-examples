TITLE MASM Template						(main.asm)

INCLUDE Irvine32.inc
.data
;For Constants
MAXLENGTH = 20
MAXVALUE = 47
MINVALUE = 0
;For Strings
myName BYTE "Programmer's Name: Daniel Kirkpatrick",0dh,0ah,0
progTitle BYTE "Title: Fibonacci Numbers",0dh,0ah,0
userName BYTE "Please enter your name: ",0
greeting1 BYTE "Hello, ",0
greeting2 BYTE "!",0dh,0ah,0
greeting3 BYTE "Welcome to the Fibonacci Number Displayer!",0dh,0ah,0
instruct1 BYTE "Enter the amount of Fibonacci Numbers you would like to see between 1 and 46: ",0
errorGreater1 BYTE "You entered a number to big.",0dh,0ah,0
errorGreater2 BYTE "Enter another number between 1-46: ",0
errorLesser1 BYTE "You entered a number to small.",0dh,0ah,0
errorLesser2 BYTE "Enter another number between 1-46: ",0
userNameInput BYTE MAXLENGTH+1 DUP(?)
numSpace BYTE ",     ",0
goodbye1 BYTE "Hope you enjoyed using the program, ",0
goodbye2 BYTE "! Bye! :D",0dh,0ah,0
;For Numbers
fibAmount DWORD ?
fibHolder1 DWORD ?
fibHolder2 DWORD ?
fibAddition DWORD ?
driverCounter DWORD ?
lineCounter DWORD ?

.code
main PROC
	call Clrscr

	;Output programmers name and program title
	mov	edx,OFFSET myName
	call WriteString
	mov edx,OFFSET progTitle
	call WriteString
	call Crlf

	;Get input from user (name and how many terms they want to see)
	;user input section
	mov edx,OFFSET userName
	call WriteString
	mov edx, OFFSET userNameInput
	mov ecx, MAXLENGTH
	call ReadString
	call Crlf
	mov edx,OFFSET greeting1
	call WriteString
	mov edx,OFFSET userNameInput
	call WriteString
	mov edx,OFFSET greeting2
	call WriteString
	call Crlf
	mov edx,OFFSET greeting3
	call WriteString
	call Crlf
	mov edx,OFFSET instruct1
	call WriteString
	call ReadDec
	mov fibAmount,eax
	
	;used to check if number is within correct number range
	;error handling section
	numCheck:
		mov eax, fibAmount
		cmp eax, MAXVALUE
		jnl greater 		;jumps if value is greater than 47
		cmp eax, MINVALUE
		jng lesser 			;jumps if value is less than 1
		jmp correctValue 	;jumps if value is correct and program proceeds
	greater:
		mov edx,OFFSET errorGreater1
		call WriteString
		mov edx,OFFSET errorGreater2
		call WriteString
		call ReadDec
		mov fibAmount,eax
		jmp numCheck
	lesser:
		mov edx,OFFSET errorLesser1
		call WriteString
		mov edx,OFFSET errorLesser2
		call WriteString
		call ReadDec
		mov fibAmount,eax
		jmp numCheck
	correctValue:
		call Crlf

	;fibonacci sequence section
	;loop to execute the fibonacci sequence
	mov ecx,0			;set counter to 1
	
	;runs the fibonacci code
	driver:
		mov driverCounter, ecx
		jmp fibonacciInit1
		driverCont:
			mov ecx, driverCounter
			mov eax, driverCounter
			cmp eax, fibAmount
			jl fibonacciLoop
			je ending
		 		
		;does only the first number of the sequence when user input = 1
		;this only executes once
		fibonacciInit1:	
			inc ecx
			mov fibHolder1, 1
			mov eax, fibHolder1
			call WriteDec
			mov edx,OFFSET numSpace
			call WriteString
			mov driverCounter, ecx
			mov lineCounter, ecx
			mov eax, fibAmount
			cmp eax, 1
			je ending
			jmp fibonacciInit2
		
		;does only the first number of the sequence when user input = 2
		;this only executes once
		fibonacciInit2:
			inc ecx
			mov fibHolder2, 1
			mov eax, fibHolder2
			call WriteDec
			mov edx,OFFSET numSpace
			call WriteString
			mov driverCounter, ecx
			mov lineCounter, ecx
			mov eax, fibAmount
			cmp eax, 2
			je ending
			jmp driverCont

		;does fibonacci math and outputs the sequence
		;this does 99% of the work
		fibonacciLoop:
			inc ecx
			mov eax, fibHolder1
			add eax, fibHolder2
			mov edx,OFFSET numSpace
			call WriteDec
			call WriteString
			mov fibAddition, eax
			mov eax, fibHolder2
			mov fibHolder1, eax
			mov eax, fibAddition
			mov fibHolder2, eax
			mov driverCounter, ecx
			jmp lineSpacing
		
		;sets 5 numbers per line
		lineSpacing:
			mov ecx, lineCounter
			inc ecx
			mov lineCounter, ecx
			mov eax, lineCounter
			cmp eax, 5
			je nextLine
			jl driverCont

		nextLine:
			mov lineCounter, 0
			call Crlf
			jmp driverCont

		;to leave the driver section and continue to ending of program
		ending:

	;exiting message
	call Crlf
	call Crlf
	mov edx,OFFSET goodbye1
	call WriteString
	mov edx,OFFSET userNameInput
	call WriteString
	mov edx,OFFSET goodbye2
	call WriteString
	call Crlf



	exit
main ENDP

END main