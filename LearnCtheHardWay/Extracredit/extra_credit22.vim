let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/LearnCtheHardWay/Extracredit
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
argglobal
%argdel
$argadd extra_credit22.c
edit ex22.c
set splitbelow splitright
wincmd _ | wincmd |
split
1wincmd k
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
2wincmd h
wincmd w
wincmd w
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe '1resize ' . ((&lines * 23 + 19) / 39)
exe 'vert 1resize ' . ((&columns * 55 + 84) / 168)
exe '2resize ' . ((&lines * 23 + 19) / 39)
exe 'vert 2resize ' . ((&columns * 56 + 84) / 168)
exe '3resize ' . ((&lines * 23 + 19) / 39)
exe 'vert 3resize ' . ((&columns * 55 + 84) / 168)
exe '4resize ' . ((&lines * 12 + 19) / 39)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 7 - ((6 * winheight(0) + 11) / 23)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
7
normal! 0
wincmd w
argglobal
if bufexists("ex22.h") | buffer ex22.h | else | edit ex22.h | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 10 - ((9 * winheight(0) + 11) / 23)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
10
normal! 0
wincmd w
argglobal
if bufexists("extra_credit22.c") | buffer extra_credit22.c | else | edit extra_credit22.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 54 - ((19 * winheight(0) + 11) / 23)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
54
normal! 0
wincmd w
argglobal
terminal ++curwin ++cols=168 ++rows=12 ++close bash -c "cd /home/hibiki/LearnCtheHardWay/Extracredit && bash"
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 47 - ((11 * winheight(0) + 6) / 12)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
47
normal! 0
lcd ~/LearnCtheHardWay/Extracredit
wincmd w
3wincmd w
exe '1resize ' . ((&lines * 23 + 19) / 39)
exe 'vert 1resize ' . ((&columns * 55 + 84) / 168)
exe '2resize ' . ((&lines * 23 + 19) / 39)
exe 'vert 2resize ' . ((&columns * 56 + 84) / 168)
exe '3resize ' . ((&lines * 23 + 19) / 39)
exe 'vert 3resize ' . ((&columns * 55 + 84) / 168)
exe '4resize ' . ((&lines * 12 + 19) / 39)
tabnext 1
badd +0 ~/LearnCtheHardWay/Extracredit/extra_credit22.c
badd +0 ~/LearnCtheHardWay/Extracredit/ex22.c
badd +5 ~/LearnCtheHardWay/Extracredit/ex22.h
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToOS
set winminheight=1 winminwidth=1
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
