.MODEL SMALL
.STACK 1000H
.Data
	number DB "00000$"
.CODE
f PROC
	PUSH BP
	MOV BP, SP
	SUB SP, 2
L1:
	MOV AX, 5       ; Line 4
	MOV [BP-2], AX
L2:
L3:
	MOV AX, 0       ; Line 5
	MOV DX, AX
	MOV AX, [BP-2]       ; Line 5
	CMP AX, DX
	JG L4
	JMP L7
L4:
	MOV AX, [BP+4]       ; Line 7
	PUSH AX
	INC AX
	MOV [BP+4], AX
	POP AX
L5:
	MOV AX, [BP-2]       ; Line 8
	PUSH AX
	DEC AX
	MOV [BP-2], AX
	POP AX
L6:
	JMP L3
L7:
	MOV AX, [BP+4]       ; Line 10
	MOV CX, AX
	MOV AX, 3       ; Line 10
	CWD
	MUL CX
	PUSH AX
	MOV AX, 7       ; Line 10
	MOV DX, AX
	POP AX       ; Line 10
	SUB AX, DX
	PUSH AX
	POP AX       ; Line 10
	JMP L10
L8:
	MOV AX, 9       ; Line 11
	MOV [BP+4], AX
L9:
L10:
	ADD SP, 2
	POP BP
	RET 2
f ENDP
g PROC
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 2
L11:
	MOV AX, [BP+6]       ; Line 18
	PUSH AX
	CALL f
	PUSH AX
	MOV AX, [BP+6]       ; Line 18
	MOV DX, AX
	POP AX       ; Line 18
	ADD AX, DX
	PUSH AX
	MOV AX, [BP+4]       ; Line 18
	MOV DX, AX
	POP AX       ; Line 18
	ADD AX, DX
	PUSH AX
	POP AX       ; Line 18
	MOV [BP-2], AX
L12:
	MOV AX, 0       ; Line 20
	MOV [BP-4], AX
L13:
	MOV AX, 7       ; Line 20
	MOV DX, AX
	MOV AX, [BP-4]       ; Line 20
	CMP AX, DX
	JL L15
	JMP L21
L14:
	MOV AX, [BP-4]       ; Line 20
	PUSH AX
	INC AX
	MOV [BP-4], AX
	POP AX
	JMP L13
L15:
	MOV AX, 3       ; Line 22
	MOV CX, AX
	MOV AX, [BP-4]       ; Line 22
	CWD
	DIV CX
	PUSH DX
	MOV AX, 0       ; Line 22
	MOV DX, AX
	POP AX       ; Line 22
	CMP AX, DX
	JE L16
	JMP L18
L16:
	MOV AX, 5       ; Line 24
	MOV DX, AX
	MOV AX, [BP-2]       ; Line 24
	ADD AX, DX
	PUSH AX
	POP AX       ; Line 24
	MOV [BP-2], AX
L17:
	JMP L14
L18:
	MOV AX, 1       ; Line 28
	MOV DX, AX
	MOV AX, [BP-2]       ; Line 28
	SUB AX, DX
	PUSH AX
	POP AX       ; Line 28
	MOV [BP-2], AX
L19:
L20:
	JMP L14
L21:
	MOV AX, [BP-2]       ; Line 32
	JMP L23
L22:
L23:
	ADD SP, 4
	POP BP
	RET 4
g ENDP
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	SUB SP, 2
	SUB SP, 2
L24:
	MOV AX, 1       ; Line 38
	MOV [BP-2], AX
L25:
	MOV AX, 2       ; Line 39
	MOV [BP-4], AX
L26:
	MOV AX, [BP-2]       ; Line 40
	PUSH AX
	MOV AX, [BP-4]       ; Line 40
	PUSH AX
	CALL g
	PUSH AX
	POP AX       ; Line 40
	MOV [BP-2], AX
L27:
	MOV AX, [BP-2]       ; Line 41
	CALL print_output
	CALL new_line
L28:
	MOV AX, 0       ; Line 42
	MOV [BP-6], AX
L29:
	MOV AX, 4       ; Line 42
	MOV DX, AX
	MOV AX, [BP-6]       ; Line 42
	CMP AX, DX
	JL L31
	JMP L38
L30:
	MOV AX, [BP-6]       ; Line 42
	PUSH AX
	INC AX
	MOV [BP-6], AX
	POP AX
	JMP L29
L31:
	MOV AX, 3       ; Line 44
	MOV [BP-2], AX
L32:
L33:
	MOV AX, 0       ; Line 45
	MOV DX, AX
	MOV AX, [BP-2]       ; Line 45
	CMP AX, DX
	JG L34
	JMP L30
L34:
	MOV AX, [BP-4]       ; Line 47
	PUSH AX
	INC AX
	MOV [BP-4], AX
	POP AX
L35:
	MOV AX, [BP-2]       ; Line 48
	PUSH AX
	DEC AX
	MOV [BP-2], AX
	POP AX
L36:
	JMP L33
L37:
	JMP L30
L38:
	MOV AX, [BP-2]       ; Line 51
	CALL print_output
	CALL new_line
L39:
	MOV AX, [BP-4]       ; Line 52
	CALL print_output
	CALL new_line
L40:
	MOV AX, [BP-6]       ; Line 53
	CALL print_output
	CALL new_line
L41:
	MOV AX, 0       ; Line 54
	JMP L43
L42:
L43:
	ADD SP, 6
	POP BP
	MOV AX,4CH
	INT 21H
main ENDP
;-------------------------------
;         print library         
;-------------------------------
;-------------------------------
END main
