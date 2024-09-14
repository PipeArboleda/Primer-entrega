void identificarFormaOnda(float voltaje) {
  if (esOndaSenoidal(voltaje)) {
    lcd.print("Senoidal");
  } else if (esOndaCuadrada(voltaje)) {
    lcd.print("Cuadrada");
  } else if (esOndaTriangular(voltaje)) {
    lcd.print("Triangular");
  } else {
    lcd.print("Desconocida");
  }
}