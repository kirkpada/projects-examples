title freq_table.asm

include Irvine32.inc

.data
;for text
myName BYTE "Name: Daniel Kirkpatrick",0dh,0ah,0
progTitle BYTE "Title: Character Frequence Table",0dh,0ah,0
target BYTE "AAEBDCFBBC",0
space1 BYTE ": ",0

;for numbers
freqTable DWORD 256 dup(0)


.code
;constructs a character frequence table
get_frequencies proc,
pString:PTR BYTE,					;pointer to point to string
pTable:PTR DWORD					;pointer to point to freq table
		
	mov esi, offset target			;move what pString is pointing at to esi
	mov edi, offset freqTable		;move what pTable is pointing at to edi
	cld								;clear direction flag

	fill_array:
		mov eax, 0
		lodsb						;sets al = [esi] and increments esi
		cmp al, 0 					;checks to see if we reach the end of the string
		je end_proc					;if it is the end, return from the proc 
		shl eax, 2
		inc DWORD PTR[edi+eax]
		jmp fill_array				;repeats loop until we reach the end of the string

	end_proc:
	ret
get_frequencies endp

print_table proc
	mov ecx, lengthof freqTable
	mov esi, offset freqTable
	mov ebx, 0

	get_freq:
		mov eax, [esi]				;gets frequency count
		cmp eax, 0 					;check to make sure count is 0
		jna next_freq				;if count is 0 jump to next freq

	mov eax, ebx					;displays the index
	call WriteChar
	mov edx, offset space1			;inserts a colon for spacing
	call WriteString
	mov eax, [esi]					;print freq count
	call WriteDec
	call Crlf

	next_freq:
		add esi, TYPE freqTable 	;points to next thing on table
		inc ebx
		loop get_freq 				;moves back up to get_freq and loops it

	call Crlf
	ret

print_table endp

main proc
	mov edx, offset myName
	call WriteString
	mov edx, offset progTitle
	call WriteString
	call Crlf

	;call get_frequencies to execute proc
	call get_frequencies
	;call print_table to display freq table
	call print_table

main endp

exit

end main