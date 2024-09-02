#!/bin/sh

function maker () {
    $MAKE $TEST_PATH LIB_PATH=$LIB_PATH LIB_NAME=$LIB_NAME $1
}

function test() {
    for j in $1; do
        $TEST_PATH/bin/$j.out $VERBOSE;
    done
}

function help () {
    echo "help"
    exit 1;
}

MAKE="make -s -C" 

TEST_PATH="/home/reina/Documents/dev/libasm_tester_leadwasp"
LIB_PATH="../libasm"
LIB_NAME="libasm.a"

LIST_MANDATORY="strlen strcpy strcmp strdup read write"
LIST_BONUS="atoi_base list_push_front list_size list_sort list_remove_if"
DONE=0


while getopts "vhp:l:" arg; do
    case $arg in 
        h)  help ;;
        p)  TEST_PATH="${OPTARG}";;
        l)  LIB_PATH="${OPTARG}";;
        n)  LIB_NAME="${OPTARG}";;
        v)  VERBOSE="verbose";;
        *)  echo "$i not supported"; exit 1;;
    esac
done


for i in "$@"; do
    case $i in 
        a)  DONE=1; maker $i && test "$LIST_MANDATORY" && test "$LIST_BONUS" ;;
        m)  DONE=1; maker $i && test "$LIST_MANDATORY" ;;
        b)  DONE=1; maker $i && test "$LIST_BONUS" ;;
        strlen | strcpy | strcmp | strdup | read | write | atoi_base | list_size | list_push_front | list_sort | list_remove_if) 
            DONE=1; maker "bin/$i.out" && $TEST_PATH/bin/$i.out $VERBOSE;;
        clear) DONE=1; maker fclean ;;
    esac
done

if [ $DONE -eq 0 ]; then
    maker m && test "$LIST_MANDATORY"
fi

