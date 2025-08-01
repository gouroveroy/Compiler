.MODEL SMALL

.STACK 1000H

.DATA

NUMBER DB "00000$"

.CODE

foo PROC
    PUSH BP
    MOV BP, SP
    MOV AX, [BP + 6]	; Line 3
    PUSH AX
    MOV AX, [BP + 4]	; Line 3
    POP BX
    ADD BX, AX
    MOV AX, BX
    PUSH AX
    MOV AX, 5
    POP BX
    CMP BX, AX
    JLE L0
    MOV AX, 0
    JMP L1
L0:
    MOV AX, 1
L1:
    CMP AX, 0
    JE L2
    MOV AX, 7
    POP BP
    RET 4
L2:
    MOV AX, [BP + 6]	; Line 7
    PUSH AX
    MOV AX, 2
    POP BX
    SUB BX, AX
    MOV AX, BX
    PUSH AX
    MOV AX, [BP + 4]	; Line 7
    PUSH AX
    MOV AX, 1
    POP BX
    SUB BX, AX
    MOV AX, BX
    PUSH AX
    CALL foo
    PUSH AX
    MOV AX, 2
    PUSH AX
    MOV AX, [BP + 6]	; Line 7
    PUSH AX
    MOV AX, 1
    POP BX
    SUB BX, AX
    MOV AX, BX
    PUSH AX
    MOV AX, [BP + 4]	; Line 7
    PUSH AX
    MOV AX, 2
    POP BX
    SUB BX, AX
    MOV AX, BX
    PUSH AX
    CALL foo
    MOV BX, AX
    POP AX
    XOR DX, DX
    MUL BX
    POP BX
    ADD BX, AX
    MOV AX, BX
    POP BP
    RET 4
    POP BP
    RET 4
foo ENDP
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    PUSH BP
    MOV BP, SP
    SUB SP, 2	; Line 12
    SUB SP, 2	; Line 12
    SUB SP, 2	; Line 12
    JMP L4
L3:
    MOV [BP - 2], AX	; Line 13
    JMP L5
L4:
    MOV AX, 7
    JMP L3
L5:
    JMP L7
L6:
    MOV [BP - 4], AX	; Line 14
    JMP L8
L7:
    MOV AX, 3
    JMP L6
L8:
    JMP L10
L9:
    MOV [BP - 6], AX	; Line 16
    JMP L11
L10:
    MOV AX, [BP - 2]	; Line 16
    PUSH AX
    MOV AX, [BP - 4]	; Line 16
    PUSH AX
    CALL foo
    JMP L9
L11:
    MOV AX, [BP - 6]	; Line 17
    CALL PRINT_OUTPUT
    CALL NEW_LINE
    MOV AX, 0
    ADD SP, 6
    POP BP
    MOV AX, 4CH
    INT 21H
MAIN ENDP

; Print procedures
NEW_LINE PROC
    PUSH AX
    PUSH DX
    MOV AH,2
    MOV DL,0DH
    INT 21H
    MOV AH,2
    MOV DL,0AH
    INT 21H
    POP DX
    POP AX
    RET
NEW_LINE ENDP

PRINT_OUTPUT PROC
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX
    PUSH SI
    LEA SI,NUMBER
    MOV BX,10
    ADD SI,4
    CMP AX,0
    JNGE NEGATE
PRINT:
    XOR DX,DX
    DIV BX
    MOV [SI],DL
    ADD [SI],'0'
    DEC SI
    CMP AX,0
    JNE PRINT
    INC SI
    MOV BYTE PTR [SI + 6], '$'
    LEA DX,SI
    MOV AH,9
    INT 21H
    POP SI
    POP DX
    POP CX
    POP BX
    POP AX
    RET
NEGATE:
    PUSH AX
    MOV AH,2
    MOV DL,'-'
    INT 21H
    POP AX
    NEG AX
    JMP PRINT
PRINT_OUTPUT ENDP
END MAIN
