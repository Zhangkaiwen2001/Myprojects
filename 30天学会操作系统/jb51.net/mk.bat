@echo off
setlocal EnableDelayedExpansion
del chinaz.com.txt /s
del หตร๗.htm /s
copy d:\jb51tools\jb_down\book\ !cd!
mkdir jb51.net
del %0 | move *.* jb51.net