/**
 * <tiedoston_nimi>.h
 * 
 * Lyhyt kuvaus luokasta. Mit� sill� tehd��n? 1-2 lausetta riitt�nee.
 * T�ss� tiedostossa esitell��n projetkin ohjelmointik�yt�nt�.
 * Pyrit��n pit�m��n rivien pituus max 80 merkiss�!
 * 
 * Esimerkki:
 *		Esimerkki esimerkki = new Esimerkki("argumentti");
 *		esimerkki->metodi();
 *		...
 * Muutama esimerkki tavallisesta k�yt�st�.
 * 
 * TODO(<oma_nimi>)
 *		- Lista..
 *			Puutteista
 *			Bugeista
 * Listan tulee olla HEADER tiedostossa, jotta nopealla vilkaisulla saadaan
 * k�sitys mit� tulee viel� tehd�. 
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
		k�ytet��n.

		Luokan esittelyss� esitell��n ensin funktiot ja sitten muuttujat.

		Nime�misk�yt�nt�;
			* Funktioiden nimet camelCasella
			* muuttujan_nimi on pienell� ja sanat erotetaan alaviivalla 
		*/

		// Konstruktori. Alustaa luokan.
		Esimerkki(std::string argumentti);

		// Esimerkki toisesta metodista.
		void metodi();

		// Muuttuja. T�m� on esimerkki.
		int public_muuttuja;

	private:
		// Tekee sit� sun t�t�, enemm�n sit�.
		void privateMetodi();

		// Private muuttuja.
		int private_boolean;

}; // <-- Muista ; !!!

// Suljetaan header guardit, huomaa kommentti #endif j�lkeen
#endif // __<luokka>_H_DEFINED__