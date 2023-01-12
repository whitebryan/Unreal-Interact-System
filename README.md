# Simple Interaction System
Very simple Interactability System Plugin with interface for use in UE5

Useable in C++/Mixed Unreal Projects

To use drop into the Plugins folder of unreal

In game put the interaction component on your button/lever/etc object and set the variables under Interact Properties. Then bind the blueprint functions you create to the delegates.

Put the InteractableComponent on the object you want to be activated like a door/platform/etc and set the variables. Then bind your blueprint functions to the delegates.

Then make an interaction action on your character have it check if whatever you are trying to interact with uses the interface and execute interact.

Examples of buttons, doors, and pressure plates included.

Now includes optional post process outline shader for highlighting interactable objects. Under Project Settings->Engine->Rendering->Postporcessing Enable Custom Depth-Stencil Pass then put the PostProccessOutline into your Postproccess volume. 
After that enable Render CustomDepth Pass on the interactables mesh and then change the custom depth stencil value when it should be outlined

Outline shader madde from these tutorials
https://www.youtube.com/channel/UC_L8NgyCVqVUUGX3tN1jtHA
https://www.tomlooman.com/unreal-engine-soft-outline/