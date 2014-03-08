/****************************************
* Libresistance.h
*
* Author:Petter Lerenius
*
* Dynamic library that calculates the total resistance
* for a number of parallel or serial connected
* resistors.
*
*  count: Antal komponenter
*  conn: Seriellt eller parallellt kopplade komponeter [ P | S ]
*  array: En pekare på en array av komponentvärden som är lika stor som count.
*  Värdet 0 skall returneras om något motstånd är noll vid
*   parallellkoppling, dvs  R1||R2=0, om R1 eller R2 är 0Ohm.
*  Biblioteket får inte krascha om en "nollpekare" skickas
*   till funktioen, dvs om array=0.
*  Om argumenten är felaktiga skall funktionen returnera -1.
*****************************************/

#ifndef RESISTANCE_H
#define RESISTANCE_H

float calc_resistance(int count, char conn, float *array);

#endif
