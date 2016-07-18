title Letter Matrix														(letter_matrix.asm)

include Irvine32.inc

.data
;for text
myName BYTE "Programmer's Name: Daniel Kirkpatrick",0ah,0dh,0
progTitle BYTE "Program Name: Letter Matrix",0ah,0dh,0
vowels BYTE "AEIOUY",0
consonants BYTE "BCDFGHJKLMNPQRSTVWXZ",0
instruct1 BYTE "This program prints a 4x4 matrix of random letters.",0
exitMess BYTE "Thanks for using the program!",0ah,0dh,0

;for numbers
numVowels DWORD 6
numCons DWORD 20

.code
;used to print out the 4x4 grids
printGrid proc
	push eax
	push ecx							;ecx will be used to count the rows
	push edx							;edx will be used to count the number of letters in each row
	mov ecx, 4

	gridRow:
		call Crlf
		mov edx, 4
	
	;used to determine whether a consonant or vowel will be chosen
	vowelOrCons:
		mov eax, 2 						;used in random number gen to get 1 or 0
		call RandomRange
		cmp eax, 0 						;compare against 0, if 0 then consonant
		jnz getVowel
		call getRandCons				;call getRandCons proc to get random consonant
		jmp printLetter

	getVowel:
		call getRandVowel				;call getRandVowel proc

	printLetter:
		call WriteChar					;output random letter
		dec edx							;decrement letter count
		jnz vowelOrCons
		dec ecx							;decrement row count when edx = 0
		jnz gridRow
		call Crlf
		pop edx
		pop ecx
		pop eax

printGrid endp

;used to get random vowel
getRandVowel proc
	push ebx
	mov eax, numVowels
	mov ebx, offset vowels
	call RandomRange					;the random range is stored in eax (0-5)
	add ebx, eax						;point ebx at the selected vowel
	mov al, [ebx]
	pop ebx
	ret

getRandVowel endp

;used to get random consonant
getRandCons proc
	push ebx
	mov eax, numCons
	mov ebx, offset consonants
	call RandomRange					;the random range is stored in eax (0-19)
	add ebx, eax						;point ebx at the selected consonant
	mov al, [ebx]
	pop ebx
	ret

getRandCons endp

main proc
	;prog name and prog title
	mov edx, offset myName
	call WriteString
	mov edx, offset progTitle
	call WriteString
	call Crlf

	mov edx, offset instruct1
	call WriteString
	call Crlf

	mov ecx, 5							;will be used to loop the printing of 5, 4x4 matrices
	call Randomize

	driverLoop:
		call printGrid
		dec ecx
		jnz driverLoop					;continues loop until ecx = 0
		call Crlf

	;exit message
	mov edx, offset exitMess
	call WriteString
	call Crlf

main endp

exit
end main