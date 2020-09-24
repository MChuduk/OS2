Set WshShell = CreateObject ("WScript.Shell")
Set fso = WScript.CreateObject("Scripting.FileSystemObject")
Set file = fso.CreateTextFile("E:\OS\Laba4\newfile.bat")
file.WriteLine("start Excel.exe")
file.Close
WshShell.Run("E:\OS\Laba4\newfile.bat")
