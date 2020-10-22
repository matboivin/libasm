%ifndef LIBASM_MACOS_INC
    %define LIBASM_MACOS_INC

    %define ERROR_VAL -1
    %define MAC_SYSCALL_CLASS_UNIX 0x2000000
    %define MAC_SYSCALL_CONSTRUCT(n) (MAC_SYSCALL_CLASS_UNIX | n)
    %define READ 3
    %define WRITE 4

%endif
