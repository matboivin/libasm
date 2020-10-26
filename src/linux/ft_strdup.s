        section .text
        global  ft_strdup
        extern  ft_strlen
        extern  ft_strcpy
        extern  malloc
        extern  __errno_location

ft_strdup:
        push    rbp                     ; enter
        mov     rbp, rsp

        push    rdi                     ; saves the string
        call    ft_strlen               ; gets the string length
        inc     rax                     ; increments for terminating character
        mov     rdi, rax                ; moves length in rdi to malloc the result

        call    malloc
        test    rax, rax                ; checks malloc return
        jz      set_errno

        mov     rdi, rax                ; moves address to be used as dst for copy
        pop     rsi                     ; restores the string as src
        call    ft_strcpy

done:
        mov     rsp, rbp                ; leave
        pop     rbp
        ret

set_errno:
        neg     rax                     ; gets the positive error code
        push    rax                     ; saves error code
        call    __errno_location        ; gets the address of the errno variable
        pop     WORD [rax]              ; restores the error code as errno value
        xor     rax, rax                ; sets the return value to 0
        jmp     done
