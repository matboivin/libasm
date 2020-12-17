# libasm - Linux and MacOS versions

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

### Installing

Clone the repository, change it to your working directory and run:

```console
$ make
```

To check the OS and the `src` directory:

```console
$ make show
```
### Tests

```
Usage: ./libasm_tester [-h | --bonus]

optional arguments:
  -h       print this usage message
  --bonus  run both mandatory and bonus tests
```

To run the test suite:

```console
$ make debug
```

### License

<a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc/4.0/88x31.png" /></a>

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License](http://creativecommons.org/licenses/by-nc/4.0/).

### Acknowledgements

School project done at [42 Paris](https://www.42.fr).
