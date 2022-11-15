:set number
:set tabstop=4
:set shiftwidth=4
:set smarttab
:set softtabstop=4
:set mouse=a
:set expandtab
:set autoindent
:set smartindent
:set ruler
:set autowrite
:set pumheight=20
:set hlsearch
" TextEdit might fail if hidden is not set.
:set hidden

" Some servers have issues with backup files, see #649.
:set nobackup
:set nowritebackup

" Give more space for displaying messages.
:set cmdheight=1

" Having longer updatetime (default is 4000 ms = 4 s) leads to noticeable
" delays and poor user experience.
:set updatetime=300

" Don't pass messages to |ins-completion-menu|.
:set shortmess+=c
syntax on

" default file decoding
:set encoding=UTF-8

" auto + smart indent for code
:set autoindent
:set smartindent
:set clipboard+=unnamedplus

 " no delays!
:set updatetime=300

:set t_Co=256
:set colorcolumn=80
:set shell=zsh

" faster updates!
:set updatetime=100

" no hidden buffers
:set hidden&

" automatically read on change
:set autoread

nnoremap <A-t> :Ttoggle<CR>
" nnoremap <A-t> :Ttoggle<cr>
" Insert new line above without going into insert mode
" (uses mark o to return to the previous cursor column)
nnoremap <A-Enter> moO<Esc>`o
" Remap C-c to <esc>
nmap <c-c> <esc>
imap <c-c> <esc>
vmap <c-c> <esc>
omap <c-c> <esc>
tnoremap <esc> <C-\><C-N>
" PLUGIN: FZF
nnoremap <silent> <Leader>b :Buffers<CR>
nnoremap <silent> <S-f> :Files<CR>
nnoremap <silent> <Leader>f :Rg<CR>
nnoremap <silent> <Leader>/ :BLines<CR>
nnoremap <silent> <Leader>' :Marks<CR>
nnoremap <silent> <Leader>g :Commits<CR>
nnoremap <silent> <Leader>H :Helptags<CR>
nnoremap <silent> <Leader>hh :History<CR>
nnoremap <silent> <Leader>h: :History:<CR>
nnoremap <silent> <Leader>h/ :History/<CR>
nnoremap <silent> <A-w> :%y+<CR>
nnoremap <silent> <C-s> :call fzf#run({
\   'tmux_height': '40%',
\   'sink':        'botright split' })<CR>
" nnoremap <A-t> :botright split +resize12 term://zsh<CR>

let mapleader=","
let g:rainbow_active = 1 "set to 0 if you want to enable it later via :RainbowToggle
let g:neoterm_default_mod = 'botright'
let g:neoterm_size = 13
let g:neoterm_autoinsert = 1

" Colorscheme
set termguicolors
let g:gruvbox_contrast_dark='medium'
let g:gruvbox_contrast_light='hard'
:colorscheme gruvbox
hi LspCxxHlGroupMemberVariable guifg=#83a598

" auto-pairs
let g:AutoPairsFlyMode = 0
let g:AutoPairsShortcutBackInsert = '<M-b>'

" Always show the signcolumn, otherwise it would shift the text each time
" diagnostics appear/become resolved.
if has("nvim-0.5.0") || has("patch-8.1.1564")
  " Recently vim can merge signcolumn and number column into one
  set signcolumn=number
else
  set signcolumn=yes
endif

" switch between split windows
for n in range(1, 9)
    exe "nnoremap <silent> <M-".n."> :".n."wincmd w<CR>"
endfor

" cursorline
augroup cursorline
    autocmd!
    autocmd WinEnter * exe winnr('$')>1 ? "set cursorline" : "set nocursorline"
augroup END

" switch between hpp and cpp
au BufEnter,BufNew *.cpp nnoremap <silent> ;p :e %<.hpp<CR>
au BufEnter,BufNew *.hpp nnoremap <silent> ;p :e %<.cpp<CR>

au BufEnter,BufNew *.cpp nnoremap <silent> ;vp :leftabove vs %<.hpp<CR>
au BufEnter,BufNew *.hpp nnoremap <silent> ;vp :rightbelow vs %<.cpp<CR>

au BufEnter,BufNew *.cpp nnoremap <silent> ;xp :leftabove split %<.hpp<CR>
au BufEnter,BufNew *.hpp nnoremap <silent> ;xp :rightbelow split %<.cpp<CR>

" surround with std::optional
nnoremap <silent> ;cso :execute 's/\(' . expand('<cWORD>') . '\)/std::optional<\1>'<CR>:noh<CR>

" zig config
au FileType zig nmap <Leader>dt <cmd>lua vim.lsp.buf.definition()<CR>
au FileType zig nmap <Leader>h  <cmd>lua vim.lsp.buf.hover()<CR>
au FileType zig nmap <Leader>p  <cmd>lua vim.lsp.buf.signature_help()<CR>
au FileType zig nmap <Leader>gd  <cmd>lua vim.lsp.buf.document_symbol()<CR>
au FileType zig setlocal omnifunc=v:lua.vim.lsp.omnifunc

" enable history for fzf
let g:fzf_history_dir = '~/.local/share/fzf-history'

" easy-motion
" disable default mappings, turn on case-insensitivity
let g:EasyMotion_do_mapping = 0
let g:EasyMotion_smartcase = 1


" Function to trim extra whitespace in whole file
function! Trim()
  let l:save = winsaveview()
  keeppatterns %s/\s\+$//e
  call winrestview(l:save)
endfun

command! -nargs=0 Trim call Trim()

" Function to set tab width to n spaces
function! SetTab(n)
  let &tabstop=a:n
  let &shiftwidth=a:n
  let &softtabstop=a:n
  set expandtab
  set autoindent
  set smartindent
endfunction

" ;t is trim
nnoremap <silent> ;t :Trim<CR>

" ;w is save
noremap <silent> ;w :update<CR>

";f formats in normal mode
noremap <silent> ;f gg=G``:w<CR>

" C/C++ indent options: fix extra indentation on function continuation
set cino=(0,W4

" colorcolumn 80, tab width 4 for shaders
autocmd BufRead,BufNewFile *.sc setlocal colorcolumn=80 | SetTab 4

" nim config
autocmd BufRead,BufNewFile *.nim  setlocal colorcolumn=80
autocmd BufRead,BufNewFile *.nims setlocal colorcolumn=80
autocmd BufRead,BufNewFile *.nim SetTab 2
autocmd BufRead,BufNewFile *.nims SetTab 2

" Binary files -> xxd
augroup Binary
  au!
  au BufReadPre  *.bin let &bin=1
  au BufReadPost *.bin if &bin | %!xxd
  au BufReadPost *.bin set ft=xxd | endif
  au BufWritePre *.bin if &bin | %!xxd -r
  au BufWritePre *.bin endif
  au BufWritePost *.bin if &bin | %!xxd
  au BufWritePost *.bin set nomod | endif
augroup END

autocmd FileType * setlocal formatoptions-=c formatoptions-=r formatoptions-=o
