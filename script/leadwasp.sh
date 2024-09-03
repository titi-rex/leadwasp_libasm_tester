#!/bin/bash

# alias lw="$(pwd)/script/leadwasp.sh -p $(pwd) -l \\\$(pwd)"
# alias leadwasp="$(pwd)/script/leadwasp.sh -p $(pwd)"

function maker () {
    $MAKE $TEST_PATH LIB_PATH=$LIB_PATH LIB_NAME=$LIB_NAME $1
}

function test() {
    for j in $1; do
        $TEST_PATH/bin/$j.out $VERBOSE;
    done
}


function greets () {
    printf "\033[1;34m
*~~~~~~~~~~~~~~~~~~~~~~*
*       LeadWasp       *
*     libasm tester    *
*~~~~~~~~~~~~~~~~~~~~~~*
    \033[0m"
}

function help () {
    echo "#==# LeadWasp, a libasm tester for 42 student #==#
* use with 'lw' or 'leadwasp' alias
* options : 
*    -p specify tester location (*default: automatically set in alias* lw/leadwasp) 
*    -l specify library location (*default:* ../)
*    -n specify library name (*default:* libasm.a)
*    -k launch test with valgrind
*    -v verbose
*    -h show help"
    exit 1;
}

MAKE="make -s -C" 

TEST_PATH=$(pwd)
LIB_PATH="../"
LIB_NAME="libasm.a"

LIST_MANDATORY="strlen strcpy strcmp strdup read write"
LIST_BONUS="atoi_base list_push_front list_size list_sort list_remove_if"
DONE=0

greets

while getopts "vhkp:l:" arg; do
    case $arg in 
        p)  TEST_PATH="${OPTARG}";;
        l)  LIB_PATH="${OPTARG}";;
        n)  LIB_NAME="${OPTARG}";;
        v)  VERBOSE="verbose";;
        k)
            if [ $(>/dev/null 2>&1 valgrind --version && echo $?) -eq 0 ]; then
                VALGRIND="valgrind --quiet --leak-check=full --errors-for-leak-kinds=all --error-exitcode=1 ";
            else
                echo "valgrind not installed!";
            fi
        ;;
        h | *)  help ;;
    esac
done


for i in "$@"; do
    case $i in 
        a | all)  DONE=1; maker $i && test "$LIST_MANDATORY" && test "$LIST_BONUS" ;;
        m | mandatory)  DONE=1; maker $i && test "$LIST_MANDATORY" ;;
        b | bonus)  DONE=1; maker $i && test "$LIST_BONUS" ;;
        strlen | strcpy | strcmp | strdup | read | write | atoi_base | list_size | list_push_front | list_sort | list_remove_if) 
            DONE=1; maker "bin/$i.out" && $VALGRIND $TEST_PATH/bin/$i.out $VERBOSE ;;
        clear) DONE=1; maker fclean ;;
    esac
done

if [ $DONE -eq 0 ]; then
    maker m && test "$LIST_MANDATORY"
fi

