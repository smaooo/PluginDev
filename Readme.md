# Text Randomizer

### How to Use
<img src=".github/text_randomizer_node_v2.png">

### Building / Packaging
The best option for packaging the `text` files is to create a Dierectory inside `Content` (e.g. `Data`) and put all these kind of files there. Then, with `Project Settings --> Project --> Packaging --> Additional Non-Asset Directories to Package` add the `Data` direcotry to be cooked / packaged with the build.

# Extra Cam Window
This is an updated and extended version of [chaosgrid's ExtraCamWindow](https://github.com/chaosgrid/ExtraCamWindow)

### Changes
* Changed Camera Component to Scene Capture Component, which means there won't be any jittering because of camera view change on each frame.
* New `UExtraCamWindowComponent` for adding to other actors, and a default `AExtraCamWindowActor` for placing in the world or creating child blueprints.
### Remarks
* True that the Extra Cam Window component is using Scene Capture Component logic for rending on the extra windows, but it doesn't mean that there's need for creating a Render Texture Target or a UMG for setting the component or the actor up. All will be handled by the Extra Cam Window Component itself, and all you need to do is to place either the actor in the world or add the component to your actor.

### Usage
You can think of this actor and component package as a Camera Actor and Component package, which means that you can either place an `Extra Cam Window Actor` from the `Place Actors` sections, or add the `Extra Cam Window` as a component to your Actor Blueprint. You can also create child/inherited Blueprints from both.

> For modifying the Extra Cam Window Properties refer to `Extra Cam Window` section in the Details pane on the Actor or Component.

<img src=".github/extra_cam_pane.png" style="width: 50%;">

> `Alt + Enter` Makes the Window Fullscreen if the window has the mouse focus.
