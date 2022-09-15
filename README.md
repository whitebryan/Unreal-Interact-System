# Simple Interaction System
Very simple Interactability System Plugin with interface for use in UE5

Useable in C++/Mixed Unreal Projects

To use drop into the Plugins folder of unreal

In game put the interaction component on your button/lever/etc object and set the variables under Interact Properties. Then bind the blueprint functions you create to the delegates.

Put the InteractableComponent on the object you want to be activated like a door/platform/etc and set the variables. Then bind your blueprint functions to the delegates.

Then make an interaction action on your character have it check if whatever you are trying to interact with uses the interface and execute interact.

Examples of buttons, doors, and pressure plates included.

