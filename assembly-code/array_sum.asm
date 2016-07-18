title Sum of an Array Row 														(array_sum.asm)

Include Irvine32.inc

.data
;for text
myName BYTE "Programmer's Name: Daniel Kirkpatrick",0ah,0dh,0
progTitle BYTE "Program Name: Sum of an Array Row",0ah,0dh,0
instruct1 BYTE "This program will return the sum of a selected row.",0ah,0dh,0
rowSelect BYTE "Select which row you want to sum (0-3): ",0
rowSum BYTE "The sum of the row is: ",0
exitMess BYTE "Thanks for using the program!",0ah,0dh,0

;for numbers
byteTable BYTE 1, 2, 3, 4, 5
		  BYTE 2, 2, 2, 2, 2
		  BYTE 5, 5, 5, 5, 5
		  BYTE 3, 3, 3, 3, 3

wordTable WORD 1, 2, 3, 4, 5
		  WORD 2, 2, 2, 2, 2
		  WORD 5, 5, 5, 5, 5
		  WORD 3, 3, 3, 3, 3

dwordTable DWORD 1, 2, 3, 4, 5
	  	   DWORD 2, 2, 2, 2, 2
	  	   DWORD 5, 5, 5, 5, 5
	  	   DWORD 3, 3, 3, 3, 3

rowSize = 5


.code
;calculates the sum of a row in a 2d array
calc_row_sum proc
	mul ecx										;row index * row size
	add ebx, eax								;row offset
	mov eax, 0 									;accumulator
	mov esi, 0 									;column index

	Loop1:
		movzx edx, BYTE ptr[ebx+esi]			;get a byte
		add eax, edx							;add to the accumulator
		inc esi									;next byte in row
		loop Loop1

	ret
calc_row_sum endp

;main driver proc
main proc
	;programmers name and program title
	mov edx, offset myName
	call WriteString
	mov edx, offset progTitle
	call WriteString
	call Crlf

	;instruction
	mov edx, offset instruct1
	call WriteString
	mov edx, offset rowSelect
	call WriteString
	call ReadInt

	;move the array into ebx and call calc_row_sum
	mov ebx, offset byteTable
	mov ecx, rowSize
	call calc_row_sum

	;output the sum of the row in the array
	mov edx, offset rowSum
	call WriteString
	call WriteDec
	call Crlf

	;exit message for program
	call Crlf
	mov edx, offset exitMess
	call WriteString
	call Crlf


main endp

exit
end main