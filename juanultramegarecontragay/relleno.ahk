#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

^j::
Toggle := !Toggle

send 2
send {Enter}
sleep 50
send 10
send {Enter}
sleep 50
send 1
send {Enter}
sleep 50
send 6
send {Enter}
sleep 50

send -1
send {Enter}
sleep 50
send 8
send {Enter}
sleep 50
send -6
send {Enter}
sleep 50
send 12
send {Enter}
sleep 50

send 7
send {Enter}
sleep 50
send 30
send {Enter}
sleep 50
send -2
send {Enter}
sleep 50
send -3
send {Enter}
sleep 50



send 1
send {Enter}
sleep 50
send 5
send {Enter}
sleep 50
send 10
send {Enter}
sleep 50
send 11
send {Enter}
sleep 50

send 3
send {Enter}
sleep 50
send -3
send {Enter}
sleep 50
send 12
send {Enter}
sleep 50
send 13
send {Enter}
sleep 50

send 5
send {Enter}
sleep 50
send 7
send {Enter}
sleep 50
send 32
send {Enter}
sleep 50
send -7
send {Enter}
sleep 50



return