# libasm

### Prerequisites

This program was developed on Debian Linux.

- GNU make and a C compiler
- NASM assembler


## Linked list structure

```c
typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;
```

| Variable | Size    |                      |
| -------- | ------- | -------------------- |
| data     | 8 bytes | Pointer to data      |
| next     | 8 bytes | Pointer to next node |
