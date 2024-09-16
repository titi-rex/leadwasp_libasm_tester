#!/bin/bash

set -e;

printf "download repo\n";
git clone git@github.com:titi-rex/leadwasp_libasm_tester.git leadwasp;

printf "settings alias in '~/.zshrc'\n";
cd leadwasp;
alias lw="$(pwd)/script/leadwasp.sh -p $(pwd) -l \"\\\$(pwd)\"";
alias leadwasp="$(pwd)/script/leadwasp.sh -p $(pwd)";
>> ~/.zshrc echo "alias lw=\"$(pwd)/script/leadwasp.sh -p $(pwd) -l \\\$(pwd)\"";
>> ~/.zshrc echo "alias leadwasp=\"$(pwd)/script/leadwasp.sh -p $(pwd)\"";
cd -;
