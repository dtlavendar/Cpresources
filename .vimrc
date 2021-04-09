
set clipboard=unnamedplus
set nocompatible
filetype off
call plug#begin("~/.vim/plugged")
Plug 'joshdick/onedark.vim'
Plug 'valloric/youcompleteme'
call plug#end()
inoremap { {}<Left>
inoremap {<CR> {<CR>}<Esc>O
inoremap {{ {
inoremap {} {}
syntax on
set termguicolors
filetype plugin indent on
set backspace=indent,eol,start
set softtabstop=4
set shiftwidth=4
set tabstop=4
set expandtab
set ruler
set showcmd
set title
colorscheme onedark
syntax enable
set rnu
set nu
