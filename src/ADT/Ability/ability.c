#include <stdio.h>
#include "ability.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor *** */
void AB_createAbility (Ability *a, boolean option){
/* Membuat ability dengan count awal sesuai spesifikasi masing-masing */
	/* KAMUS LOKAL */
	/* ALGORITMA */
	if (option) {
		Count(*a) = 10;
	} else {
		Count(*a) = 1;
	}
	Active(*a) = false;
}
/* *** Kondisi Aktivasi Ability *** */
void AB_activate (Ability *a){
/* Mengaktifkan ability */
	/* KAMUS LOKAL */
	/* ALGORITMA */
	Active(*a) = true;
}
void AB_deactivate (Ability *a){
/* Menon-aktifkan ability dan mereset durasi menjadi 0 */
	/* KAMUS LOKAL */
	/* ALGORITMA */
	Active(*a) = false;
}
boolean AB_isActive(Ability a){
/* Mengirimkan true jika ability active */
	/* KAMUS LOKAL */
	/* ALGORITMA */
	return (Active(a) == true);
}
/* *** Operasi terhadap Ability *** */
void AB_stackAbility(Ability *a){
/* Menambahkan count ability sesuai spesifikasi
   Hanya dapat digunakan pada rts */
	/* KAMUS LOKAL */
	/* ALGORITMA */
	Count(*a)++;
}
void AB_useAbility(Ability *a){
/* Mengurangi count ability sesuai spesifikasi */
	/* KAMUS LOKAL */
	/* ALGORITMA */
	Count(*a)--;
}

void AB_reset(Ability *a, boolean option){
/* Reset count sesuai spesifikasi masing-masing */
	/* KAMUS LOKAL */
	/* ALGORITMA */
	AB_createAbility(a,option);
}