#ifndef EFFECT_H
#define EFFECT_H
#include <iostream>
#include <string>
using namespace std;

enum EffectType {
    PASSIVE,    // Selalu aktif (stat boost)
    ACTIVE,     // Perlu diaktifkan manual
    TRIGGERED   // Aktif otomatis saat kondisi tertentu
};

struct effect {
    string nama;
    string deskripsi;
    
    // ⭐ TAMBAHAN BARU - Gameplay properties
    EffectType type;          // Tipe effect (PASSIVE/ACTIVE/TRIGGERED)
    string statAffected;      // Stat yang dipengaruhi (HEALTH, INTELLECT, etc)
    int value;                // Nilai efek (+5 health, +2 intellect, dll)
    bool isActive;            // Status aktif/tidak
    
    effect* next;
};

// ⭐ Function signature BERUBAH - sekarang terima lebih banyak parameter
effect* createeffect(string effectname, string desc, 
                     EffectType type = PASSIVE, 
                     string statAffected = "", 
                     int value = 0);

void addeffect(effect*& head, string effectname, string desc, 
               EffectType type = PASSIVE, 
               string statAffected = "", 
               int value = 0);

void activateEffect(effect* effectNode);
void deactivateEffect(effect* effectNode);
effect* findEffect(effect* head, string effectName);

#endif