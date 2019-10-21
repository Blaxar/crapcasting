crapcasting
===========

A wannabe RayCasting engine, we'll see...

This project is nothing more yet than an attempt to implement Raycasting: the late 80'/early 90's rendering method to have a 3D-ish envrionments, which can be seen as a (very) simplified version of Raytracing, focused on rendering walls.

See this: http://www.permadi.com/tutorial/raycast/

It is not made to be optimized for the moment (this might come to change though), it's barely a prototype but I find it funny to develop.

So far you will need OpenCV (to draw columns in a custom window) and libcaca (to draw columns in a terminal), you'll also need either CMake or (preferably) Meson to build the project.

Note that OpenCV will later be dropped as a dependency and CMake build support will probably be deprecated.

Controls are set for an Azerty (french) keyboard:

Z - Move forward.
S - Move backward.
Q - Turn left.
D - Turn right.

You can tune them by editing the source code.
