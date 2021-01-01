set nocompatible
filetype off
call plug#begin("~/.vim/plugged")
  " Plugin Section
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'frazrepo/vim-rainbow'
Plug 'bling/vim-bufferline'
Plug 'lifepillar/vim-solarized8'
Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'altercation/vim-colors-solarized'
Plug 'valloric/youcompleteme'
Plug 'jiangmiao/auto-pairs'
Plug 'altercation/solarized'
Plug 'rakr/vim-one'
Plug 'morhetz/gruvbox'
Plug 'joshdick/onedark.vim'
Plug 'crusoexia/vim-monokai'
let g:ycm_confirm_extra_conf = 0
let g:airline_theme='one'
Plug 'dracula/vim'
Plug 'arcticicestudio/nord-vim'
call plug#end()

au FileType c,cpp,objc,objcpp call rainbow#load()

syntax on
set termguicolors
filetype plugin indent on
set backspace=indent,eol,start
set softtabstop=4
set shiftwidth=4
set tabstop=4
set expandtab
set number
set ruler
set showcmd
set title
colorscheme monokai
set background=dark
syntax enable
" open new split panes to right and below
set splitright
set splitbelow
" turn terminal to normal mode with escape
tnoremap <Esc> <C-\><C-n>
" start terminal in insert mode
au BufEnter * if &buftype == 'terminal' | :startinsert | endif
" open terminal on ctrl+n
function! OpenTerminal()
  split term://bash
  resize 10
endfunction
nnoremap <c-n> :call OpenTerminal()<CR>

