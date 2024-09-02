
# LeadWasp

A libasm tester for 42 student struggling to find asm lover to help them


## Installation

```bash
  
 git clone git@github.com:titi-rex/leadwasp_libasm_tester.git leadwasp
 cd leadwasp
 alias lw="$(pwd)/script/leadwasp.sh -p $(pwd) -l \"\\\$(pwd)\""
 alias leadwasp="$(pwd)/script/leadwasp.sh -p $(pwd)"
 >> ~/.zshrc echo "alias lw=\"$(pwd)/script/leadwasp.sh -p $(pwd) -l \\\$(pwd)\""
 >> ~/.zshrc echo "alias leadwasp=\"$(pwd)/script/leadwasp.sh -p $(pwd)\""

```
You can clone the repo where you want, just make sure to set the good path in alias (*should be automatic if you follow Installation*)
## Usage
You are provided with two alias :  use `lw` inside your project repo or `leadwasp` with `-l path/to/libasm.a` 

You can ask for `all`/`a``bonus`/`b` `mandatory`/`m` or specific function : 
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
- `-k` launch test with valgrind
- `-v` verbose
- `-h` show help



## License

[MIT](https://choosealicense.com/licenses/mit/)

