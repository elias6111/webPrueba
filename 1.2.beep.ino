#include "pitches.h"

#define BUZZER_PIN 9

// Cara al Sol (Juan Tellería), transportado a Do mayor, compás 6/8.
// Duración de una corchea en milisegundos: bájalo para que vaya más rápido.
const int CORCHEA = 200;

// Pares nota/duración. La duración se mide en corcheas:
// 1 = corchea, 2 = negra, 3 = negra con puntillo, 6 = blanca con puntillo.
int melodia[] = {
  NOTE_E5, 2,  NOTE_D5, 1,
  NOTE_C5, 3,  NOTE_C5, 3,
  NOTE_C5, 2,  NOTE_G4, 1,  NOTE_C5, 2,  NOTE_D5, 1,
  NOTE_E5, 4,  NOTE_D5, 2,
  NOTE_C5, 4,  NOTE_C5, 2,
  NOTE_F5, 4,  NOTE_F5, 2,
  NOTE_E5, 2,  NOTE_D5, 1,  NOTE_C5, 2,  NOTE_E5, 1,
  NOTE_D5, 5,
  NOTE_E5, 2,  NOTE_D5, 1,
  NOTE_C5, 3,  NOTE_C5, 3,
  NOTE_C5, 2,  NOTE_G4, 1,  NOTE_C5, 2,  NOTE_D5, 1,
  NOTE_E5, 4,  NOTE_D5, 2,
  NOTE_C5, 3,  NOTE_E5, 3,
  NOTE_D5, 3,  NOTE_C5, 3,
  NOTE_B4, 3,  NOTE_A4, 3,
  NOTE_G4, 5,
  NOTE_B4, 2,  NOTE_C5, 1,
  NOTE_D5, 4,  NOTE_B4, 2,
  NOTE_G4, 2,  NOTE_G4, 1,  NOTE_G5, 2,  NOTE_F5, 1,
  NOTE_E5, 4,  NOTE_D5, 2,
  NOTE_C5, 3,  NOTE_B4, 2,  NOTE_C5, 1,
  NOTE_D5, 4,  NOTE_B4, 2,
  NOTE_G4, 2,  NOTE_G4, 1,  NOTE_G5, 2,  NOTE_F5, 1,
  NOTE_E5, 4,  NOTE_D5, 2,
  NOTE_C5, 5,
  NOTE_E5, 4,  NOTE_F5, 2,
  NOTE_E5, 2,  NOTE_D5, 1,  NOTE_D5, 2,  NOTE_B4, 1,
  NOTE_A4, 3,  NOTE_C5, 3,
  NOTE_E5, 4,  NOTE_E5, 2,
  NOTE_F5, 3,  NOTE_E5, 2,  NOTE_D5, 1,
  NOTE_C5, 3,  NOTE_B4, 3,
  NOTE_A4, 5,
  NOTE_D5, 4,
  NOTE_E5, 2,
  NOTE_D5, 2,  NOTE_C5, 1,  NOTE_B4, 2,  NOTE_A4, 1,
  NOTE_G4, 3,  NOTE_B4, 3,
  NOTE_D5, 4,  NOTE_D5, 2,
  NOTE_E5, 3,  NOTE_D5, 2,  NOTE_C5, 1,
  NOTE_B4, 3,  NOTE_A4, 3,
  NOTE_G4, 5,
  NOTE_E5, 2,  NOTE_D5, 1,
  NOTE_C5, 3,  NOTE_C5, 3,
  NOTE_C5, 2,  NOTE_G4, 1,  NOTE_C5, 2,  NOTE_D5, 1,
  NOTE_E5, 4,  NOTE_D5, 2,
  NOTE_C5, 4,  NOTE_C5, 2,
  NOTE_F5, 4,  NOTE_F5, 2,
  NOTE_E5, 2,  NOTE_D5, 1,  NOTE_C5, 2,  NOTE_E5, 1,
  NOTE_D5, 5,
  NOTE_E5, 2,  NOTE_D5, 1,
  NOTE_C5, 3,  NOTE_C5, 3,
  NOTE_C5, 2,  NOTE_G4, 1,  NOTE_C5, 2,  NOTE_D5, 1,
  NOTE_E5, 4,  NOTE_D5, 2,
  NOTE_C5, 3,  NOTE_E5, 3,
  NOTE_D5, 3,  NOTE_C5, 3,
  NOTE_B4, 3,  NOTE_A4, 3,
  NOTE_G4, 5,
  NOTE_B4, 2,  NOTE_C5, 1,
  NOTE_D5, 4,  NOTE_B4, 2,
  NOTE_G4, 2,  NOTE_G4, 1,  NOTE_G5, 2,  NOTE_F5, 1,
  NOTE_E5, 4,  NOTE_D5, 2,
  NOTE_C5, 4,  NOTE_G4, 2,
  NOTE_C5, 4,  NOTE_G4, 2,
  NOTE_E4, 2,  NOTE_G4, 1,  NOTE_C5, 2,  NOTE_D5, 1,
  NOTE_E5, 5,
  NOTE_E5, 3,  NOTE_G5, 2,  NOTE_F5, 1,
  NOTE_E5, 3,  NOTE_E5, 3,
  NOTE_D5, 2,  NOTE_C5, 1,  NOTE_D5, 2,  NOTE_E5, 1,
  NOTE_C5, 6
};

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  int longitud = sizeof(melodia) / sizeof(int);

  for (int i = 0; i < longitud; i += 2) {
    int duracion = melodia[i + 1] * CORCHEA;

    tone(BUZZER_PIN, melodia[i], duracion * 0.9);  // 90 % sonando, 10 % de silencio
    delay(duracion);
    noTone(BUZZER_PIN);
  }

  delay(4000);  // Pausa de 4 segundos antes de repetir
}
