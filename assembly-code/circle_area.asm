title Area of a Circle  															(circle_area.asm)

include Irvine32.inc

.data
;for text
myName BYTE "Programmer's Name: Daniel Kirkpatrick",0ah,0dh,0
progTitle BYTE "Program Name: Area of a Circle Calculator",0ah,0dh,0
instruct1 BYTE "This program is used to calculate the area of a circle.",0ah,0dh,0
getRad BYTE "Pick the radius of the circle you want to calculate: ",0
areaCalc BYTE "The area of the circle is: ",0
exitMess BYTE "Thanks for using the program!",0ah,0dh,0

;for numbers
radius QWORD ?
rad_sqrd QWORD ?
area QWORD ?

.code
;get the radius for the circle
get_radius proc
	mov edx, offset getRad 				;get input from user
	call WriteString
	call ReadFloat						;push input onto ST(0)

	fst radius 							;store ST(0) into radius

	ret

get_radius endp

;calculate the area of the circle using radius from input
circle_calc proc
	fmul radius 						;mul radius with ST(0)
	fstp rad_sqrd						;stores radius*radius and pops off stack
	fldpi 								;load pi onto the stack
	fmul rad_sqrd						;mul rad_sqrd*pi for area

	mov edx, offset areaCalc
	call WriteString
	call WriteFloat
	call Crlf

	ret
circle_calc endp


main proc
	FINIT								;initialize FPU

	;prog name and prog title
	mov edx, offset myName
	call WriteString
	mov edx, offset progTitle
	call WriteString
	call Crlf

	;prog instructions
	mov edx, offset instruct1
	call WriteString
	call Crlf

	;make call to get user input
	call get_radius

	;make call to circle_calc proc
	call circle_calc

	;exit message
	call Crlf
	mov edx, offset exitMess
	call WriteString
	call Crlf

main endp


exit
end main