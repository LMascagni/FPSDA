@echo off
setlocal enabledelayedexpansion

rem Chiedi il nome del programma
set /p programName=Inserisci il nome del programma da avviare: 

rem Chiedi fino a che numero arrivare
set /p maxNum=Inserisci il numero massimo (es. 10): 

rem Numero iniziale
set num=0

rem Ciclo principale
:loop
rem Formatta il numero a due cifre (ad esempio, 00, 01, 02, ecc.) se il numero è minore di 10

if %num% lss 10 (
    set paddedNum=0%num%
) else (
    set paddedNum=%num%
)

set paddedNum=!paddedNum:~-2!

rem Genera i nomi dei file
set dateFile=files\date_!paddedNum!.txt
set dispFile=files\disponibilita_!paddedNum!.txt

rem Controlla se i file esistono
if not exist "!dateFile!" (
    echo File "!dateFile!" non trovato. Uscita.
    goto end
)
if not exist "!dispFile!" (
    echo File "!dispFile!" non trovato. Uscita.
    goto end
)

rem Esegui il programma con i file
echo Avvio programma "!programName!" con "!dateFile!" e "!dispFile!"
!programName! !dateFile! !dispFile!
echo -------------
rem Incrementa il numero
set /a num+=1

rem Controlla se il numero massimo è stato raggiunto
if !num! gtr %maxNum% goto end

rem Torna al ciclo
goto loop

:end
echo Operazione completata.
pause
