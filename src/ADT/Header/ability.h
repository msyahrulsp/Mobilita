/* File: ability.h */
/* *** Definisi ABSTRACT DATA TYPE ABILITY *** */

#ifndef ABILITY_H
#define ABILITY_H

#include "boolean.h"

typedef struct {
	int count;
	boolean active;
} Ability;

/* *** Notasi Akses: Selektor POINT *** */
#define Count(P) (P).count
#define Active(P) (P).active

/*	Terdapat dua jenis ability :
	SpeedBoost : gunakan opsi true pada fungsi/prosedur
	ReturnToSender : gunakan opsi false */
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor *** */
void AB_createAbility (Ability *a, boolean option);
/* Membuat ability dengan count awal sesuai spesifikasi masing-masing */

/* *** Kondisi Aktivasi ABILITY *** */
void AB_activate (Ability *a);
/* Mengaktifkan ability */
void AB_deactivate (Ability *a);
/* Menon-aktifkan ability */
boolean AB_isActive(Ability a);
/* Mengirimkan true jika ability active */

/* *** Operasi terhadap Ability *** */
void AB_stackAbility(Ability *a);
/* Menambahkan count ability sesuai spesifikasi
   Hanya dapat dilakukan untuk rts */
void AB_useAbility(Ability *a);
/* Mengurangi count ability sesuai spesifikasi */
void AB_reset(Ability *a, boolean option);
/* Reset count sesuai spesifikasi masing-masing */

#endif