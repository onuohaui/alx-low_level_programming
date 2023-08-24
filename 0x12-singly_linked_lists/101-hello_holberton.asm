section .data
hello_message db "Hello, Holberton", 0xA
hello_message_len equ $ - hello_message

section .text
global main
extern printf

main:
; set up the arguments for printf
mov rdi, hello_message      ; format string
xor rax, rax                ; 0 floating point registers used

; call printf
call printf

; exit the program
xor rdi, rdi                ; exit status 0
ret
