/**
 * <tiedoston_nimi>.h
 * 
 * Lyhyt kuvaus luokasta. Mitä sillä tehdään? 1-2 lausetta riittänee.
 * Tässä tiedostossa esitellään projetkin ohjelmointikäytäntö.
 * Pyritään pitämään rivien pituus max 80 merkissä!
 * 
 * Esimerkki:
 *		Esimerkki esimerkki = new Esimerkki("argumentti");
 *		esimerkki->metodi();
 *		...
 * Muutama esimerkki tavallisesta käytöstä.
 * 
 * TODO(<oma_nimi>)
 *		- Lista..
 *			Puutteista
 *			Bugeista
 * Listan tulee olla HEADER tiedostossa, jotta nopealla vilkaisulla saadaan
 * käsitys mitä tulee vielä tehdä. 
 */

// Header guardit
#ifndef __<luokka>_H_DEFINED__
#define __<luokka>_H_DEFINED__

// Includet
#include <stdio>
#include <string>
#include "SDL.h"
// ...

// Constantit aina CAPSI TAI SHIFTI POHJASSA.
#define CONST 100

// Luokan nimi isolla alkukirjaimella
class Esimerkki {
	public:
		/* 
		Ennen metodeja ja muuttujia kerrotaan hyvin lyhyesti mihin funktiota 
		käytetään.

		Luokan esittelyssä esitellään ensin funktiot ja sitten muuttujat.

		Nimeämiskäytäntö;
			* Funktioiden nimet camelCasella
			* muuttujan_nimi on pienellä ja sanat erotetaan alaviivalla 
		*/

		// Konstruktori. Alustaa luokan.
		Esimerkki(std::string argumentti);

		// Esimerkki toisesta metodista.
		void metodi();

		// Muuttuja. Tämä on esimerkki.
		int public_muuttuja;

	private:
		// Tekee sitä sun tätä, enemmän sitä.
		void privateMetodi();

		// Private muuttuja.
		int private_boolean;

}; // <-- Muista ; !!!

// Suljetaan header guardit, huomaa kommentti #endif jälkeen
#endif // __<luokka>_H_DEFINED__