title array_reverse.asm

include Irvine32.inc
MAXLENGTH = 20

;All the boring stuff (variable declarations)
.data
;For Text
myName BYTE "Name: Daniel Kirkpatrick",0dh,0ah,0
progTitle BYTE "Title: Array Reverse",0dh,0ah,0
instruct1 BYTE "Enter length of array from 1 - 20: ",0
exit1 BYTE "Thanks for using the program! :D",0
orderList BYTE "The list in order: ",0
numSpace BYTE ", ",0
revList BYTE "The list in reverse order: ",0

;For Numbers
myArr DWORD MAXLENGTH dup(0)
count DWORD ?


;All the fun stuff (code)
.code
;ask user for size of array
get_count proc
	push ebp			;ebp is pointing to base of stack
	mov ebp, esp		;ebp and esp are pointing to same place in stack 
	;instruct user to enter number from 1-20 (size of array)
	mov edx, offset instruct1
	call WriteString
	call ReadInt		;read in array size
	mov count, eax
	mov edx, [ebp+8]
	mov [ebx], eax
	pop ebp				;get ebp off the stack
	ret 				;return to main proc

get_count endp

;fills the array using the count from user
arr_fill proc
	push ebp			;point ebp to base of stack
	mov ebp, esp		;set ebp and esp to same position
	mov ecx, [ebp+8]	
	mov edi, [ebp+12]
	mov ebx, 0

;loop used to fill the array with however many spots the user input
fill_spots:
	mov eax, ebx
	add eax, 1
	mov [edi], eax
	add edi, 4
	inc ebx
	mov edx, offset numSpace
	call WriteDec
	call WriteString
	loop fill_spots

	call Crlf
	pop ebp				;get ebp off the stack
	ret 				;return to main proc

arr_fill endp

;reverses what is inside the array
reverse proc
	push ebp			;point ebp to base of stack
	mov ebp, esp		;set ebp and esp to same position
	mov edx, [ebp+8]
	mov esi, [ebp+12]
	dec edx
	
;loop used to reverse the array order without making a new array
reverse_order:	
	mov eax, edx
	add eax, 1
	call WriteDec
	mov al, ','
	call WriteChar
	mov al, 0
	call WriteChar
	mov eax, [esi+edx*4]
	dec edx
	cmp edx, 0
	jge reverse_order

	call Crlf
	pop ebp				;get ebp off the stack
	ret 				;return to main proc

reverse endp


main proc
	;Programmer name and Program title
	mov edx, offset myName
	call WriteString
	mov edx, offset progTitle
	call WriteString
	call Crlf

	;make call to get_count proc to get size of array
	push offset count
	call get_count
	add esp, 4
	call Crlf

	;call to arr_fill proc to fill array with numbers
	mov edx, offset orderList
	call WriteString
	push offset myArr
	push count
	call arr_fill
	call Crlf

	;call to reverse proc to reverse order of the array
	mov edx, offset revList
	call WriteString
	push offset myArr
	push count
	call reverse
	add esp, 8
	call Crlf

	;exit message
	mov edx, offset exit1
	call WriteString
	call Crlf
	call Crlf

	exit
main endp

END main