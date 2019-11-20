#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRSIZ 10

typedef struct {
        char    name[STRSIZ];
        double  diameter;
        int     moons;
        double  orbit_time,
                rotation_time;
    } planet_t;

void print_planet(planet_t pl);

int main(void){
    
    planet_t current_planet, previous_planet,
             blank_planet = {"", 0, 0, 0, 0};

    strcpy(current_planet.name, "Jupiter");
    current_planet.diameter = 142800;
    current_planet.moons = 16;
    current_planet.orbit_time = 11.9;
    current_planet.rotation_time = 9.925;

    print_planet(current_planet);

    return 0;
} 

void print_planet(planet_t pl){
    printf("Planet: %s\nDiameter: %lf\nMoons: %d\nOrbit time: %lf\nRotation time: %lf", 
            pl.name, pl.diameter, pl.moons, pl.orbit_time, pl.rotation_time);
}