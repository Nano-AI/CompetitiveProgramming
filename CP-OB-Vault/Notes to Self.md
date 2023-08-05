.vimrc file:
```vim
" Define a function to compile and run C++ code
filetype plugin on
syntax on

nnoremap <C-c> :Gpp
" nnoremap <C-x> :!start "./%:r.exe"

command Gpp :!g++ -o  "%:r.exe" "%" -std=c++11 && "./%:r.exe" && "./%:r.exe"
command GppRun :!"./%:r.exe"



set number                     " Show current line number
set relativenumber             " Show relative line numbers

set autoindent 

" set tabwidth=4
```

template:
```c++
#include <bits/stdc++.h>

using namespace std;

void useIO(const char* file_name) {
	string file = file_name;
	freopen((file + ".in").c_str(), "r", stdin);
	freopen((file + ".out").c_str(), "w", stdout);
}

int main() {
	return 0;
}
```