# Path-Tracer
Simple path tracer in C

## Compiling the project
Run compile script in compile.sh in your terminal

## Choosing your scene
Modify buildscene.c to include objects you would like to path trace!
Remember to specify the colors and the properties of your objects.

## Running the Path Tracer
Once compiled, run ./PathTracer [resolution] [recursion_depth] [num_of_samples] [anti_aliasing_flag] file_name.ppm
in terminal. Fill in the parameters of your own choice.

## Sample scenes rendered from the Path Tracer

### Cornell box with importance sampling and explicit sampling
![Sample Render 1](cornell.png?raw=true "Title")

### Cornell box with more objects in the scene
![Sample Render 2](cg_conqueror.png?raw=true "Title")



