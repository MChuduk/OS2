Option Explicit
Dim fso, fileA, fileB
Const ForReading = 1
Const ForWriting = 2

Set fso = WScript.CreateObject("Scripting.FileSystemObject")
Set fileA = fso.CreateTextFile("E:\OS\Laba4\fileA.txt", ForWriting)
fileA.WriteLine("content of fileA")
fileA.Close

Set fileA = fso.OpenTextFile("E:\OS\Laba4\fileA.txt", ForReading)
Set fileB = fso.CreateTextFile("E:\OS\Laba4\fileB.txt", ForWriting)
fileB.WriteLine(fileA.ReadAll)
fileA.Close 
fileB.Close 
