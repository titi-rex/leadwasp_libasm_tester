
# LeadWasp

A libasm tester for 42 student struggling to find asm lover to help them 
Now based on [libunit](https://github.com/titi-rex/libunit)

## Installation


```bash
bash -c "$(curl -fsSL https://raw.githubusercontent.com/titi-rex/leadwasp_libasm_tester/main/script/install.sh)"

```
You can clone the repo where you want, the good path should be set automatically in alias (*if you followed Installation*)

Dependencies : `make gcc`

## Usage
You are provided with two alias :  use `lw` inside your project repo or `leadwasp` with `-l path/to/libasm.a` 

You can ask for `all`/`a` `bonus`/`b` `mandatory`/`m` or specific function : 
```bash
    lw mandatory
    lw -v a
    lw -v strlen strcpy list_size
    lw bonus
    leadwasp -l /home/ellanae/libasm -n libasm.v2.a

```

Flags :
- `-p` specify tester location (*default: automatically set in alias* `lw/leadwasp`) 
- `-l` specify library location (*default:* `../`)
- `-n` specify library name (*default:* `libasm.a`)
- `-k` launch test with valgrind (wip)
- `-v` verbose
- `-q` quit (wip)
- `-c` clear obj and exe files
- `-h` show help

## License

[MIT](https://choosealicense.com/licenses/mit/)

