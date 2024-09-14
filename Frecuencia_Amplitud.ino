#include <Adafruit_LiquidCrystal.h>

int pinAnalogico = A0;
int valor = 0;
float voltaje = 0.0;
float amplitud = 0.0;
float frecuencia = 0.0;
unsigned long ultimaHora = 0;
Adafruit_LiquidCrystal lcd(0);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);  // Iniciar la pantalla LCD
}

void loop() {
  valor = analogRead(pinAnalogico);
  
  // Convertir el valor analógico a voltaje
  voltaje = (valor / 1023.0) * 5.0;

  // Cálculo de amplitud pico-pico
  if (voltaje > amplitud) {
    amplitud = voltaje;
  }

  // Cálculo de frecuencia (simplificado)
  unsigned long tiempoActual = millis();
  if (voltaje >= 2.5 && (tiempoActual - ultimaHora) > 500) {
    frecuencia = 1000.0 / (tiempoActual - ultimaHora);
    ultimaHora = tiempoActual;
  }

  // Mostrar valores en la pantalla LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Amp: ");
  lcd.print(amplitud);
  lcd.print(" V");
  lcd.setCursor(0, 1);
  lcd.print("Freq: ");
  lcd.print(frecuencia);
  lcd.print(" Hz");
  
  delay(500);  // Retardo para evitar sobrecarga
}