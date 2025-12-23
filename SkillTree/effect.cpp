#include "effect.h"


effect* createeffect(string effectname, string desc, EffectType type, 
                     string statAffected, int value) {
    effect* newEffect = new effect;
    newEffect->nama = effectname;
    newEffect->deskripsi = desc;
    

    newEffect->type = type;
    newEffect->statAffected = statAffected;
    newEffect->value = value;
    newEffect->isActive = (type == PASSIVE); 
    
    newEffect->next = nullptr;
    return newEffect;
}


void displayEffects(effect* head) {
    if (head == nullptr) {
        cout << "  [No Effects]" << endl;
        return;
    }
    
    effect* temp = head;
    while (temp != nullptr) {
        string status = temp->isActive ? "[ACTIVE]" : "[INACTIVE]";
        
        cout << "  • " << temp->nama << " " << status << endl;
        cout << "    " << temp->deskripsi << endl;
    
        if (temp->statAffected != "" && temp->value != 0) {
            cout << "    Effect: " << temp->statAffected << " ";
            if (temp->value > 0) cout << "+";
            cout << temp->value << endl;
        }
        
        temp = temp->next;
    }
}

void activateEffect(effect* effectNode) {
    if (effectNode != nullptr && effectNode->type != PASSIVE) {
        effectNode->isActive = true;
        cout << "[+] Effect '" << effectNode->nama << "' activated!" << endl;
    }
}
