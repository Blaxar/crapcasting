crapcasting
===========

A wannabe RayCasting engine, we'll see...

This project is nothing more yet than an attempt to implement RayCasting: the late 80'/early 90's rendering method to have a 3D-ish envrionments, which can be seen as a (very) simplified version of the raytracing, focused on rendering walls.

See this: http://www.permadi.com/tutorial/raycast/

It is not made to be optimized for the moment (this might come to change though), it's barely a prototype but I find it funny to develop.

So far the only specific library required is OpenCV (used to draw columns), you'll also need CMake to build the project.

Controls are made for an Azerty (french) keyboard:

Z - Move forward.
S - Move backward.
Q - Turn left.
D - Turn right.

You can adapt them in the source code.
