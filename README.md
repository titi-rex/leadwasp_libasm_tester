# LibUnit

A brief C framework for unit testing, based on 42 rush libunit


## Features

- Sequentially execute each test in its own process
- Handle writting/reading tests on STDIN/STDOUT
- Colorfull
- Two timeout mode
- Catch a lot of signals


## Installation

The lib can be compiled via `make` 

Use `make test` to start example tests

```bash
  make
  make test
```
Dependencies : `make gcc`
## Usage
This lib's goal is to handle unit test functions, those functions should be prototyped like this :

```c
int     test_01(void)
```
and return `0` if test was succesfull or `-1`.


#### Functions :

- Load one test on a test list, with his name (max 32 char), the test functions and optionnal [flags](#flags) 
```c
void	test_loader(t_test **test_list, char *test_name, t_test_func function, uint8_t flags);
```

- Loop through the test list and execute test, take the tested function name 
```c
int		test_launcher(t_test **test_list, const char *name);
```
These two functions should be used inside a launcher function, which should be called by main. Your main can call all launcher successively or register them inside a t_mifunc array and use `test_start`
- Execute launcher stored in ftab based on arg received by main, no arg execute all launcher
```c
int		test_start(t_mifunc *ftab, size_t len, int ac, char **argv);
```
Don't hesitate to look tests-example !

#### Flags: 
- `FLAG_STDIN` : allow to use test writting/reading on stdin/stdout 
- `FLAG_TIMEOUT_L`	: use a longer timeout 

## Used By


- [LeadWasp](https://github.com/titi-rex/leadwasp_libasm_tester)


## License

[MIT](https://choosealicense.com/licenses/mit/)

