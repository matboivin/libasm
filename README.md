# libasm - Linux and MaOS versions

`libasm` is an individual school project at [42 Paris](https://www.42.fr) campus.

42 is a private, non-profit and tuition-free Computer Science school based on peer-to-peer learning and hands-on projects.

> The aim of this project is to get familiar with assembly language.

### Disclaimer

This project is a school assignment. It was done for **learning purposes** and is thus **not intended for production**.  
Don't copy. Learn.  

I gathered all the resources that were helpful in the `doc` directory. You can check it out but don't copy and paste code without understanding how it works.

### Prerequisites

- GNU make and a C compiler
- NASM assembler

### Usage

Clone the repository, change it to your working directory and run:
```console
$ make
```

### Common tasks

To display the OS and the src directory:

```console
$ make show
```

To create the `libasm_tester` test suite:
```console
$ make debug

$./libasm_tester -h
Usage: ./libasm_tester [-h | --bonus]

optional arguments:
  -h       print this usage message
  --bonus  run both mandatory and bonus tests
```

### Acknowledgements

School project done at [42 Paris](https://www.42.fr).
