title: sieve_of_eraosthenes.asm

include Irvine32.inc

MAX_COUNT = 50

.data
;for text
myName BYTE "Name: Daniel Kirkpatrick",0dh,0ah,0
progTitle BYTE "Title: Sieve of Eratosthenes (Prime Numbers)",0dh,0ah,0
prime BYTE "The prime numbers are: ",0
endProg BYTE "End of prog.",0

;for numbers
myArr DWORD MAX_COUNT dup(?)

.code
;initialize array with 0
array_init proc,
pArr: PTR dword,
tempCount1: ptr dword

	mov al, 0 							;make al = 0
	mov edi, pArr 						;make edi point to array
	mov ecx, tempCount1					;set up loop counter
	cld 								;clear direction flag
	rep stosd							;store 0 in the array
	ret 								;return to main

array_init endp

;proc which searches through and marks which numbers are prime
prime_search proc
	mov ecx, 0 						;set ecx to 0
		
	fillArrayLoop:	
		mov eax, ecx				;set eax to counter value in ecx
		add eax, 2					;since we start at 2, add 2 to counter value
		mov [myArr+4*ecx], eax		;insert value into array
		inc ecx	
		cmp ecx, MAX_COUNT			;compare counter to MAX_COUNT
		jb fillArrayLoop			;jump to loop start if we are not finished

	mov ecx, 0						;set ecx to 0

	loop1:							;outer outer loop
		mov ebx, ecx				;set ebx to become a counter for inner loop (loop2)
		inc ebx						;loop starts at ecx + 1
		cmp [myArr+4*ecx], 1		;check to see if value is correct
		jne loop2					;if not jump to inner loop (loop2)
		check1:						;check point
			inc ecx					;increment loop 1 (ecx) counter
			cmp ecx, MAX_COUNT		;check to see if we are done
			jb loop1				;if not finished jump to loop start
			jmp finished			;else we are all done

	loop2:							;first inner loop
		cmp [myArr+4*ebx], 1		;check to see if value is correct
		jne loop3					;if not jump to second inner loop (loop3)
		check2:						;check point
			inc ebx					;increment loop 2 (ebx) counter
			cmp ebx, MAX_COUNT		;check to see if we are done
			jb loop2				;if not finished go to loop start.
			jmp Check1				;first inner loop finished (loop2), return to loop1

	loop3:							;this loops does our prime checking
		mov edx, 0					;set edx to 0
		mov eax, 0					;set eax to 0
		mov eax, [myArr+4*ebx]		;place the number we want to check in eax
		div [myArr+4*ecx]			;divide the number in eax with the value from outer loop
		cmp edx, 0					;check for remainder
		je remove					;if there is no remainder the number in eax is not prime
		; set number to equal 1
		Check3:						;check point
			jmp Check2				;finished, jump to check point 2 (loop2)

	remove:
	mov [myArr+4*ebx], 1			;number is not prime, set to -1
	jmp Check3						;jump to check point 3 (check3)

	finished:
	ret

prime_search endp

;proc which prints the prime numbers
print_primes proc,
pArr: PTR dword,						;pointer to array
tempCount1: PTR DWORD 					;pointer to count

	cld									;clear direction flag
	mov esi, pArr 						;set esi to where the ptr starts
	mov edi, esi						;set edi to point at what esi is pointing to
	mov ecx, tempCount1					;move temp counter into ecx
	mov al, 0 							;move 0 into the al register

	Loop4:
		mov al, 0 						;reset al to 0
		cmp [edi], al					;compare al with spot in array
		je if_zero						;if zero then jump to if_zero label

		lodsd 							;loads dword from memory into eax register
		call WriteInt					;output prime number
		mov al, ','						;makes output look cleaner
		call WriteChar

	if_zero:
		loop Loop4 						;keeps looping Loop3 until the compare is not equal to 0

	call Crlf
	call Crlf

	ret 								;return to main

print_primes endp

main proc
	mov edx, offset myName
	call WriteString
	mov edx, offset progTitle
	call WriteString
	call Crlf

	mov edx, offset prime
	call WriteString

	push MAX_COUNT						;push count onto stack
	push offset myArr					;push array onto stack
	call array_init						;call proc to run

	push MAX_COUNT 						;push count onto stack
	push offset myArr					;push array onto stack
	call prime_search					;call proc to run

	push MAX_COUNT						;push count onto stack
	push offset myArr					;push array onto stack
	call print_primes					;call proc to run

main endp

exit

end main