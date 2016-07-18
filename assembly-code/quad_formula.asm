title Quadratic Formula 															(quad_formula.asm)

include Irvine32.inc

.data
;for text
myName BYTE "Programmer's Name: Daniel Kirkpatrick",0ah,0dh,0
progTitle BYTE "Program Name: Quadratic Formula",0ah,0dh,0
instruct1 BYTE "This program will calculate zeros using the quadratic formula.",0dh,0ah,0
instruct2 BYTE "Insert cofficients using the form: ax^2 + bx + c = 0",0dh,0ah,0
answer1 BYTE "The zeros for your function are: ",0
answer2 BYTE " and ",0
error1 BYTE "Your coefficients produce a non-real number!!",0dh,0ah,0
co_a BYTE "Insert coefficient a: ",0
co_b BYTE "Insert coefficient b: ",0
co_c BYTE "Insert coefficient c: ",0
exitMess BYTE "Thanks for using the program!",0ah,0dh,0

;for numbers
get_a QWORD ?
get_b QWORD ?
get_c QWORD ?
num1 QWORD 4.0
compNum QWORD 0.0
b_sq_hold QWORD ?
fourac_hold QWORD ?
sqrt_hold QWORD ?
twoa_hold QWORD ?
bplussqrt_hold QWORD ?
bminussqrt_hold QWORD ?
final1 QWORD ?
final2 QWORD ?

.code
;proc to get coefficients
get_coeff proc
	mov edx, offset instruct2
	call WriteString

	;get coeff a
	mov edx, offset co_a
	call WriteString
	call ReadFloat
	fstp get_a

	;get coeff b
	mov edx, offset co_b
	call WriteString
	call ReadFloat
	fstp get_b

	;get coeff c
	mov edx, offset co_c
	call WriteString
	call ReadFloat
	fstp get_c

	ret 										;return to main proc
get_coeff endp

;proc to solve for quadratic equation
quad_equation proc
	;b squarded
	fld get_b									;push get_b into ST(0)
	fmul get_b									;mul ST(0) and get_b
	fstp b_sq_hold								;store result in b_sq_hold and pop off ST(0)

	;4ac
	fld get_a									;push get_a into ST(0)
	fld get_c 									;push get_c into ST(0), moves get_a to ST(1)
	fmul ST(0), ST(1)							;mul ST(0) and ST(1), stores in ST(0)
	fmul num1									;mul ST(0) and num1
	fstp fourac_hold							;store result in fourac_hold and pop off ST(0)

	;check to see if square root will lead to imaginary number
	fld fourac_hold
	fld b_sq_hold
	fcomi ST(0), ST(1)
	jb error
	ja continue

	continue:
		;2a
		fld get_a								;push get_a into ST(0)
		fmul get_a
		fstp twoa_hold

		;sqrt(b^2 - 4ac)
		fld b_sq_hold							;push b_sq_hold into ST(0)
		fsub fourac_hold						;subtract b_sq_hold and fourac_hold and store into ST(0)
		fsqrt									;does sqrt of what is stored in ST(0)
		fcom compNum
		fstp sqrt_hold							;store sqrt result and pop off ST(0)
		
		;-b + sqrt
		fld get_b								;push get_b into ST(0)
		fchs									;change sign of b
		fadd sqrt_hold							;add sqrt and -b 
		fstp bplussqrt_hold

		;-b - sqrt
		fld get_b								;push get_t into ST(0)
		fchs									;change sign of b
		fsub sqrt_hold							;sub sqrt and -b
		fstp bminussqrt_hold

		;divide by 2a
		fld bplussqrt_hold						;push into ST(0)
		fld twoa_hold							;push into ST(0), ST(0) -> ST(1)
		fdivp									;div ST(0) and ST(1), pop after div
		mov edx, offset answer1
		call WriteString
		call WriteFloat

		fld bminussqrt_hold						;push into ST(0)
		fld twoa_hold							;push into ST(1), ST(0) -> ST(1)
		fdivp									;div ST(0) and ST(1), pop after div
		mov edx, offset answer2
		call WriteString
		call WriteFloat

		jmp return

	error:
		mov edx, offset error1
		call WriteString
		call Crlf
		jmp return

	return:
		ret 									;return to main proc
quad_equation endp


main proc
	FINIT										;initialize FPU

	;prog name and prog title
	mov edx, offset myName
	call WriteString
	mov edx, offset progTitle
	call WriteString
	call Crlf

	;prog instructions
	mov edx, offset instruct1
	call WriteString

	;call get coefficients proc
	call get_coeff

	;call quadratic equation proc
	call quad_equation

	;exit message
	call Crlf
	call Crlf
	mov edx, offset exitMess
	call WriteString
	call Crlf

main endp


exit
end main