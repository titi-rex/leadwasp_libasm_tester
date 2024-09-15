#!/bin/bash

# alias lw="$(pwd)/script/leadwasp.sh -p $(pwd) -l \\\$(pwd)"
# alias leadwasp="$(pwd)/script/leadwasp.sh -p $(pwd)"

function maker () {
    $MAKE $TEST_PATH LIBASM=$LIB_PATH/$LIB_NAME $1
}


function greets () {
    printf "\033[1;34m
*~~~~~~~~~~~~~~~~~~~~~~*
*       LeadWasp       *
*     libasm tester    *
*~~~~~~~~~~~~~~~~~~~~~~*\033[0m
"
}

function help () {
    echo "#==# LeadWasp, a libasm tester for 42 student #==#
* use with 'lw' or 'leadwasp' alias
* options : 
*    -p specify tester location (*default: automatically set in alias* lw/leadwasp) 
*    -l specify library location (*default:* ../)
*    -n specify library name (*default:* libasm.a)
*    -k launch test with valgrind (WIP)
*    -v verbose (WIP)
*    -q quiet (WIP)
*    -c clear tests obj file
*    -h show help"
    exit 1;
}

MAKE="make -s -C" 

TEST_PATH=$(pwd)
LIB_PATH=".."
LIB_NAME="libasm.a"

LIST_MANDATORY="strlen strcpy strcmp strdup read write"
LIST_BONUS="atoi_base list_push_front list_size list_sort list_remove_if"
DONE=0
OPTIND=1

greets

while getopts "vcqhkp:l:" arg; do
    case $arg in 
        p)  TEST_PATH="${OPTARG}";;
        l)  LIB_PATH="${OPTARG}";;
        n)  LIB_NAME="${OPTARG}";;
        v)  VERBOSE="";;
        q)  VERBOSE="";;
        c)  maker fclean; exit 0;;
        k)
            if [ $(>/dev/null 2>&1 valgrind --version && echo $?) -eq 0 ]; then
                VALGRIND="valgrind --quiet --leak-check=full --errors-for-leak-kinds=all --error-exitcode=1 ";
                VALGRIND="";
            else
                echo "valgrind not installed!";
            fi
        ;;
        h | *)  help ;;
    esac
done


for i in "$@"; do
    case $i in 
        mandatory | m )  maker $i; $VALGRIND $TEST_PATH/leadwasp $VERBOSE; exit 0;;
        b | bonus )  maker $i; $VALGRIND $TEST_PATH/leadwasp_bonus $VERBOSE; exit 0;;
        a | all )  maker $i; $VALGRIND $TEST_PATH/leadwasp $VERBOSE; $VALGRIND $TEST_PATH/leadwasp_bonus $VERBOSE; exit 0;;
        strlen | strcpy | strcmp | strdup | read | write )
            DONE=1; maker $i; $VALGRIND $TEST_PATH/leadwasp $i $VERBOSE ;;
        atoi_base | list_size | list_push_front | list_sort | list_remove_if) 
            DONE=1; maker $i; $VALGRIND $TEST_PATH/leadwasp_bonus $i $VERBOSE ;;
    esac
done

if [ $DONE -eq 0 ]; then
    maker m && $VALGRIND $TEST_PATH/leadwasp $VERBOSE;
fi
