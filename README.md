# Simple Interaction System
Very simple Interactability System with interface

Useable in C++/Mixed Unreal Projects

To use drop the CPP files into Source/MYPROJECTNAME/ and drop the uasset file in the Content folder. Then change the MYPROJECT_API in the headers to your correct project name. Regenerate your Visual Studio files and compile. 

In game put the interaction component on your button/lever/etc object and set the variables under Interact Properties. Then bind the blueprint functions you create to the delegates.

Put the InteractableComponent on the object you want to be activated like a door/platform/etc and set the variables. Then bind your blueprint functions to the delegates.

Then make an interaction action on your character have it check if whatever you are trying to interact with uses the interface and execute interact.

