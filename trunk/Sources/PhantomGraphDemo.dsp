# Microsoft Developer Studio Project File - Name="Constraints" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** NICHT BEARBEITEN **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=Constraints - Win32 Debug
!MESSAGE Dies ist kein gültiges Makefile. Zum Erstellen dieses Projekts mit NMAKE
!MESSAGE verwenden Sie den Befehl "Makefile exportieren" und führen Sie den Befehl
!MESSAGE 
!MESSAGE NMAKE /f "PhantomGraphDemo.mak".
!MESSAGE 
!MESSAGE Sie können beim Ausführen von NMAKE eine Konfiguration angeben
!MESSAGE durch Definieren des Makros CFG in der Befehlszeile. Zum Beispiel:
!MESSAGE 
!MESSAGE NMAKE /f "PhantomGraphDemo.mak" CFG="Constraints - Win32 Debug"
!MESSAGE 
!MESSAGE Für die Konfiguration stehen zur Auswahl:
!MESSAGE 
!MESSAGE "Constraints - Win32 Release" (basierend auf  "Win32 (x86) Console Application")
!MESSAGE "Constraints - Win32 Debug" (basierend auf  "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Constraints - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "include" /I "$(3DTOUCH_BASE)\include" /I "$(3DTOUCH_BASE)\utilities\include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 hl.lib hlu.lib hd.lib hdu.lib glut32.lib /nologo /subsystem:console /machine:I386 /libpath:"$(3DTOUCH_BASE)\lib" /libpath:"$(3DTOUCH_BASE)\utilities\lib"

!ELSEIF  "$(CFG)" == "Constraints - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "include" /I "$(3DTOUCH_BASE)\include" /I "$(3DTOUCH_BASE)\utilities\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 hl.lib hlud.lib hd.lib hdud.lib glut32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"$(3DTOUCH_BASE)\lib" /libpath:"$(3DTOUCH_BASE)\utilities\lib"

!ENDIF 

# Begin Target

# Name "Constraints - Win32 Release"
# Name "Constraints - Win32 Debug"
# Begin Group "source"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "hapticgraphclasses"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\hapticgraphclasses\DragObjectHandler.cpp
# End Source File
# Begin Source File

SOURCE=.\source\hapticgraphclasses\DragObjectHandler.h
# End Source File
# Begin Source File

SOURCE=.\source\hapticgraphclasses\GraphScene.cpp
# End Source File
# Begin Source File

SOURCE=.\source\hapticgraphclasses\GraphScene.h
# End Source File
# Begin Source File

SOURCE=.\source\hapticgraphclasses\HapticAction.h
# End Source File
# Begin Source File

SOURCE=.\source\hapticgraphclasses\HapticConstraint.cpp
# End Source File
# Begin Source File

SOURCE=.\source\hapticgraphclasses\HapticConstraint.h
# End Source File
# Begin Source File

SOURCE=.\source\hapticgraphclasses\HapticCursor.cpp
# End Source File
# Begin Source File

SOURCE=.\source\hapticgraphclasses\HapticCursor.h
# End Source File
# Begin Source File

SOURCE=.\source\hapticgraphclasses\HapticDevice.cpp
# End Source File
# Begin Source File

SOURCE=.\source\hapticgraphclasses\HapticDevice.h
# End Source File
# Begin Source File

SOURCE=.\source\hapticgraphclasses\HapticObject.cpp
# End Source File
# Begin Source File

SOURCE=.\source\hapticgraphclasses\HapticObject.h
# End Source File
# Begin Source File

SOURCE=.\source\hapticgraphclasses\Node.cpp
# End Source File
# Begin Source File

SOURCE=.\source\hapticgraphclasses\Node.h
# End Source File
# Begin Source File

SOURCE=.\source\hapticgraphclasses\Utilities.cpp
# End Source File
# Begin Source File

SOURCE=.\source\hapticgraphclasses\Utilities.h
# End Source File
# End Group
# Begin Group "businesslogic"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\businesslogic\IBusinessAdapter.h
# End Source File
# Begin Source File

SOURCE=.\source\businesslogic\IObserver.h
# End Source File
# Begin Source File

SOURCE=.\source\businesslogic\Observable.cpp
# End Source File
# Begin Source File

SOURCE=.\source\businesslogic\Observable.h
# End Source File
# End Group
# Begin Group "exceptionclasses"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\source\exceptionclasses\HapticsExceptions.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\source\Main.cpp
# End Source File
# End Group
# End Target
# End Project
