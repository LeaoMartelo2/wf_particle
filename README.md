# wf_particle

Particle system prototype for [Wireframe Engine](https://github.com/LeaoMartelo2/wireframe_game)

(This project uses [Raylib](https://github.com/raysan5/raylib))

(This project uses [nob.h](https://github.com/tsoding/nob.h))


<img align="center" src="image.gif">

## Configuring the project

The source code is pretty simple, everything is on [main.c](src/main.c)\
Keep in mind this is only a prototype.

Changing the settings can be done by changing the `#define`s at the top of the file.

 - MAX_PARTICLES

Defines the maxt ammount of particles in the screen before it starts replacing older ones.

 - PARTICLE_ACCELERATION_X 
 - PARTICLE_ACCELERATION_Y 

Defines the acceleration multiplier on the X and Y axis of the particle.

 - PARTICLE_VEL_RANGE_X
 - PARTICLE_VEL_RANGE_Y 

Define a comma separated value of the velocity multiplier for the X and Y axis.\
example: `#define PARTICLE_VEL_RANGE_X -5, 5`

 - PARTICLE_SPAWN_DEVIATION 

Max distance in pixels the particle can spawn away from the cursor.

 - PARTICLE_INITIAL_SIZE 

Initial size of the particle. Shrinks by default.

 - PARTICLE_MAIN_COLOR 
 - PARTICLE_ALT_COLOR 

Particle colors. Alternative color has a proportion of 3/10. 

 - PARTICLE_DECAY_RATE 

How fast the particle changes size. Usually negative value.

## Building the project

First you need to boostrap [nob](https://github.com/tsoding/nob.h)

```shell
cc nob.c -o nob.o
```
You only need to do this for the first time.

After that, compile the project with:
```shell
./nob
```
and run the program with:
```shell
./main
```
