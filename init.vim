set nocompatible
filetype off
call plug#begin("~/.vim/plugged")

Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'nanotech/jellybeans.vim'
Plug 'rafi/awesome-vim-colorschemes'
Plug 'vim-scripts/matrix.vim'
Plug 'frazrepo/vim-rainbow'
Plug 'bling/vim-bufferline'
Plug 'lifepillar/vim-solarized8'
Plug 'altercation/vim-colors-solarized'
Plug 'valloric/youcompleteme'
Plug 'jiangmiao/auto-pairs'
Plug 'altercation/solarized'
Plug 'rakr/vim-one'
Plug 'morhetz/gruvbox'
Plug 'joshdick/onedark.vim'
Plug 'vim-syntastic/syntastic'
Plug 'crusoexia/vim-monokai'
Plug 'ryanoasis/vim-devicons'
if !exists('g:airline_symbols')
    let g:airline_symbols = {}
endif
let g:ycm_confirm_extra_conf = 0
let g:airline_left_sep = '»'
let g:airline_left_sep = '▶'
let g:airline_right_sep = '«'
let g:airline_right_sep = '◀'
let g:airline_symbols.linenr = '␊'
let g:airline_symbols.linenr = '␤'
let g:airline_symbols.linenr = '¶'
let g:airline_symbols.branch = '⎇'
let g:airline_symbols.paste = 'ρ'
let g:airline_symbols.paste = 'Þ'
let g:airline_symbols.paste = '∥'
let g:airline_symbols.whitespace = 'Ξ'


let g:airline_left_sep = ''
let g:airline_left_alt_sep = ''
let g:airline_right_sep = ''
let g:airline_right_alt_sep = ''
let g:airline_symbols.branch = ''
let g:airline_symbols.readonly = ''
let g:airline_symbols.linenr = ''
Plug 'dracula/vim'
Plug 'arcticicestudio/nord-vim'
Plug 'sonph/onehalf'
call plug#end()
let g:airline#extensions#tabline#enabled = 1
au FileType c,cpp,objc,objcpp call rainbow#load()
syntax on
set termguicolors
filetype plugin indent on
set backspace=indent,eol,start
set softtabstop=4
set shiftwidth=4
set tabstop=4
colorscheme gruvbox
set expandtab
set ruler
set showcmd
set title
set background=dark
syntax enable
set splitright
set splitbelow
if (has("nvim"))
  let $NVIM_TUI_ENABLE_TRUE_COLOR=1
endif
set nu rnu
set noswapfile
nnoremap // :noh<return>
tnoremap <Esc> <C-\><C-n>

au BufEnter * if &buftype == 'terminal' | :startinsert | endif

function! OpenTerminal()
  split term://bash
  resize 10
endfunction
nnoremap <c-n> :call OpenTerminal()<CR>
