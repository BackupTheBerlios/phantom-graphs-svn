---------------------------------------------------------------------------
SENSABLE TECHNOLOGIES INC(R)
Copyright 2004 SensAble Technologies, Inc. All rights reserved.
3D Touch(TM) SDK - OpenHaptics(TM) toolkit v1.01.44
---------------------------------------------------------------------------

The material embodied in this software and use of this software is
subject to the terms and conditions of the clickthrough Development
License Agreement. 

For customer support: 
  http://dsc.sensable.com/  

---------------------------------------------------------------------------
System Requirements
---------------------------------------------------------------------------
The OpenHaptics toolkit requires certain hardware and
software components to be able to work properly. They are listed below.

Hardware
-------- 
    Intel Pentium(R) II or higher or select AMD processor.
    30 MB disk space and 128 MB RAM.
    One of the supported devices from PHANTOM(R) family of haptic devices:
      PHANTOM(R) Omni(TM)
      PHANTOM(R) Desktop(TM)
      PHANTOM(R) Premium 1.5/6DOF (Parallel Port)
      PHANTOM(R) Premium 3.0/6DOF (Parallel Port)
      PHANTOM(R) Premium A 1.0/1.5/3DOF (Parallel Port/PCI Card)
      PHANTOM(R) Premium L 3.0/3DOF (Parallel Port/PCI Card)


Software
---------
  Windows(R) 2000 or XP

Compilers
---------

  Microsoft(R) Visual C++ 6.0 or later

Drivers
---------
  PHANTOM Device Driver v 4.2.30

INSTALLATION
---------------------------------------------------------------------------

Installation instructions:
Step 1: Uninstall previously installed software using the Add/Remove
        Programs icon in the control panel.
Step 2. Insert the CD into your CD-ROM drive.
Step 3. In Windows Explorer, locate the drive letter associated with your
         CD_ROM Drive and double-click it.
Step 4. Install the device drivers by running the setup program in the
        “PHANTOM Device Drivers” folder. Make sure that you
        select the right type of device on the installation dialog (e.g.
        for Omni select Omni, etc). If you are asked to reboot, please do
        so. After rebooting, your device will be
        recognized, and you can run “PHANTOM Test” to calibrate it.
Step 5. Install the SDK by running the setup program in the 
        “OpenHaptics toolkit” folder. Our installation program will 
        install GLUT libraries by default, as those are used by our 
        graphics source code examples.  However, you will have the option
        to not install glut.  After installation, you will find extended
        documentation in the doc folder under the installation root.

Licensing
---------------------------------------------------------------------------

The OpenHaptics toolkit v1.01.44 now requires a license file to run the HDAPI and the 
HLAPI programs. Once you have received your license file, it is recommended that
you place it in a local directory (eg. C:\OpenHaptics License). You should then
set an environment variable named "OH_SDK_LICENSE_PATH" and set the value as the 
location of the license file. 

As an alternative, you could place the license file in the same folder as your
OpenHaptics program's executable file. 

Setting the environment variable is the recommended method for managing your
licensing. 


Changes from OpenHaptics v1.0
-----------------------------
- Licensing was added to the HDAPI and HLAPI (see above).
- Fixed bug where the proxy rotation/transform was incorrect when there is
rotation in the modelview matrix.
- Fixed haptic kicking in certain cases with non-manifold surfaces.

Changes from OpenHaptics v0.9 Limited Release
---------------------------------------------------------------------------
- Addition of HapticMouse utility library which allows you to use the 
haptic device to control the mouse cursor.  Full source for this library
is provided.  See the HapticMaterials sample program for example usage.
- Ability to create callback shapes that use lines and points as local
features.  Note that this has changed the interface for the closest feature
callback for callback shapes and will require modification of client code 
to use the new interface.
- Support for surfaces that are changing dynamically from frame to frame,
using the HL_SHAPE_DYNAMIC_SURFACE_CHANGE hint.
- Ability to query and change the haptic device used by a haptic rendering
context using the new hlContextDevice, hlGetCurrentDevice, and 
hlGetCurrentContext functions.
- Changed hlMakeCurrent and hdMakeCurrentDevice to be managed on a per
thread basis.
- Ability to combine HLAPI and HDAPI programs by scheduling HDAPI
servo thread callbacks that bracket the HLAPI servo loop code.
- Ability to have multiple rendering contexts use the same haptic device
concurrently.
- Improvements to the hluFit routines to allow fitting of the haptic
workspace to a subset of the graphics view frustum.
- Ability to query touch state and reaction force on a per shape basis,
using new hlGetShape functions.
- Motion events may now also be handled in the collision thread, allowing
for more frequent sampling of proxy position.
- Additional sample programs: HapticViewer, HapticMaterials, 
SimpleDeformableSurface, and SimpleRigidBody.  See the code sample
descriptions for details.

Changes from HDAPI 1.0
---------------------------------------------------------------------------
- Addition of the new Haptic Library API.
- HD_NOMINAL_MAX_DAMPING accessor has been added as a paramater for
hdGetDoublev.
- A bug has been fixed in the reporting of calibration status for 
PHANTOM Desktop and Omni devices.
- hduRecord functionality has been migrated to the HDU library.
- Several geometry utility classes have been added: hduLine, hduLineSegment, 
hduPlane, and hduQuaternion.
- The workspace mapping technique utilized by hduMapWorkspaceViewEx, 
hduMapWorkspaceView, and hduMapWorkspace has been improved to yield better 
utilization of the haptic workspace and motion within the view.

KNOWN ISSUES
---------------------------------------------------------------------------

- Compatability with HDAPI version 1.0:
The HDAPI library version 1.01 is not binary or source compatible with
version 1.0.  In order to allow future support for languages other than
C/C++, the calling convention of scheduler callback functions was changed 
to stdcall.  This will require programmers to add HDCALLBACK to the
declarations of all callback functions passed to hdScheduleSynchronous
and hdScheduleAsynchronous.  For example the declaration:

HDCallbackCode MyCallback(void *pUserData)	

would need to be changed to:

HDCallbackCode HDCALLBACK MyCallback(void *pUserData)

- Compatability with HLAPI 0.9:
HLAPI v0.9 programs which used the callback shape 
HL_SHAPE_CLOSEST_POINT callback function must be changed to use the
new HL_SHAPE_CLOSEST_FEATURES callback function.  Specifically, calls
of the form:
hlCallback(HL_SHAPE_CLOSEST_POINT, 
	  (HLcallbackProc) closestSurface, 
	  &myObj);
must be changed to:
hlCallback(HL_SHAPE_CLOSEST_FEATURES, 
          (HLcallbackProc) closestSurface, 
	  &myObj);
and the interface for the callback function must be changed from:
HLboolean HLCALLBACK closestSurface(const HLdouble *queryPt, 
                                    HLdouble *closestPt,
                                    HLdouble *closestNormal,
                                    void* userData)
to
HLboolean HLCALLBACK closestSurface(const HLdouble *queryPt, 
                                    const HLdouble *targetPt,
				    HLgeom* geom,
                                    HLdouble *closestPt,
                                    void* userData)
In addition local features should be specified in the callback
using the new hlLocalFeature routines.

- Dynamically changing depth buffer shapes.
Using depth buffer shapes which are changing dynamically, are front 
and back touchable, and have the haptic camera view enabled will allow
the proxy to fall through the surface of the shape when you are not in
contact with the shape.  Potential workarounds are to use front or back
only touchability, disable the haptic camera view or use a feedback 
buffer shape.

- Haptic camera view and fast moving dynamic objects.
Using haptic camera view with shapes which are moving quickly may
allow those objects to pass through the proxy without generating any
forces.  This is because objects which are moving very quickly may
not be visible in the haptic camera view.  Disabling haptic camera view
will prevent this.



---------------------------------------------------------------------------

Copyright © 2004 SensAble Technologies, Inc. All rights reserved. 
3D Touch, FreeForm, FreeForm Concept, FreeForm Modeling, 
FreeForm Modeling Plus, FreeForm Mold, GHOST, HapticSound, OpenHaptics, 
PHANTOM, PHANTOM Desktop, PHANTOM Omni, SensAble, SensAble Technologies, 
Inc., Splodge, and Splodge design are trademarks or registered trademarks
of SensAble Technologies, Inc. Other brand and product names are 
trademarks of their respective holders.

The system is protected by one of more of the following U.S. Patents:  
5,587,937; 5,625,576; 5,898,599; 6,084,587; 6,111,577; 6,191,796; 
6,369,834; 6,405,158; 6,417,638; 6,421,048; 6,552,722; 6,671,651; and
6,792,398.  
Other patents pending.

---------------------------------------------------------------------------



