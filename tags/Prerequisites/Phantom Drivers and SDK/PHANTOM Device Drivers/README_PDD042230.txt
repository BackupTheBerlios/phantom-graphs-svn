---------------------------------------------------------------------------
Copyright © 1993-2004 SensAble Technologies, Inc. All rights reserved. 
3D Touch, FreeForm, FreeForm Concept, FreeForm Modeling, 
FreeForm Modeling Plus, FreeForm Mold, GHOST, HapticSound, OpenHaptics, 
PHANTOM, PHANTOM Desktop, PHANTOM Omni, SensAble, SensAble Technologies, 
Inc., Splodge, and Splodge design are trademarks or registered trademarks
of SensAble Technologies, Inc. Other brand and product names are 
trademarks of their respective holders.

The system is protected by one of more of the following U.S. Patents:  
5,587,937; 5,625,576; 5,898,599; 6,084,587; 6,111,577; 6,191,796; 
6,369,834; 6,405,158; 6,417,638; 6,421,048; 6,552,722; 6,671,651; and 6,792,398.  
Other patents pending.

---------------------------------------------------------------------------

Release Notes for PHANTOM(R) Device Drivers (PDD)
Version 4.2.30
Microsoft(R) Windows(R) 2000/XP
9/30/04

---------------------------------------------------------------------------

The following issues have been resolved in the current Version 4.2.30 PDD release:

   This PDD resolves the issue where the PHANTOM(R) Omni(TM) gimbal calibration 
   was incorrect if you started an HDAPI or HLAPI application with the stylus in
   the inkwell.

---------------------------------------------------------------------------

The following issues have been resolved in the Version 4.2.29 PDD release:

   Improvements have been made to the accuracy of the thermal model for the 3.0/6DOF
   Phantom(R) device. The change(s) were made to stave off force degradation at 
   elevated motor temperatures.


---------------------------------------------------------------------------

The following issues have been resolved in the Version 4.2.28 PDD release:

1. The problem of a Ghost max force error appearing when using the PHANTOM(R)
   3.0/6DOF device with the Dice demo(TM) has been fixed.

2. The PHANTOM Omni device no longer becomes unrecognized when removing another 
   plug and play device from your computer.

   This PDD fixes the problem where if you have a PHANTOM Omni installed 
   and you insert another plug and play device (i.e. a USB hard drive) and 
   then remove the device, the PHANTOM Omni became disconnected or unrecognized. 


---------------------------------------------------------------------------

The following issues have been resolved in the Version 4.2.27 PDD release:

1. PHANTOM Omni overheating message in FreeForm(R) Concept(TM) using a 
   laptop.
 
   This PDD version fixes the problem where users may encounter an error message 
   after starting the FreeForm Concept application on a laptop, minimizing 
   the Concept application window for a period of time (~ 30 minutes) 
   and then maximizing the Concept application whilst the PHANTOM Omni device is 
   attached to the laptop.


---------------------------------------------------------------------------

The following issues were resolved in the Version 4.2.26 PDD release:

1. Blue screen crash using the CoulombForceDual program with two or more PHANTOM 
   Omni devices has been resolved.

2. Daisy chaining two or more PHANTOM Omni devices now works.

3. The PHANTOM Omni device will now calibrate automatically if it is in the inkwell 
   when an application is started and will properly calibrate after quitting and 
   re-launching an application.

4. The user is no longer prompted to browse for the system 1394 file during the 
   installation of PHANTOM Omni hardware; the 1394 file is now found automatically 
   during the PHANTOM Omni hardware installation.

---------------------------------------------------------------------------

