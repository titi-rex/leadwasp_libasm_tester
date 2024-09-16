#!/bin/bash

set -e;

git clone git@github.com:titi-rex/leadwasp_libasm_tester.git ~/leadwasp;
cd ~/leadwasp;
alias lw="$(pwd)/script/leadwasp.sh -p $(pwd) -l \"\\\$(pwd)\"";
alias leadwasp="$(pwd)/script/leadwasp.sh -p $(pwd)";
>> ~/.zshrc echo "alias lw=\"$(pwd)/script/leadwasp.sh -p $(pwd) -l \\\$(pwd)\"";
>> ~/.zshrc echo "alias leadwasp=\"$(pwd)/script/leadwasp.sh -p $(pwd)\"";
cd -;
