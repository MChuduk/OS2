Option Explicit
Dim WshShell, PathToFile 
Set WshShell = WScript.CreateObject("WScript.Shell")
PathToFile = "E:\OS\Laba4\test.txt"
WshShell.Run "notepad " &PathToFile
