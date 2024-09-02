#!/bin/bash


# alias lw="$(pwd)/script/leadwasp.sh -p $(pwd) -l \\\$(pwd)"
# alias leadwasp="$(pwd)/script/leadwasp.sh -p $(pwd)"

while getopts "vhp:l:" arg; do
    case $arg in 
        p)  TEST_PATH="${OPTARG}";;
        h | l | v)  ;;
        *)  exit 1;;
    esac
done


if [ $(>/dev/null 2>&1 gum -v && echo $?) -eq 0 ]; then
    $TEST_PATH/script/tester_gum.sh $@
else
    $TEST_PATH/script/tester.sh $@
fi

