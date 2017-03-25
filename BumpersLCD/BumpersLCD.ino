/**
 * Este programa testa o funcionamento dos dois bumpers do robô.
 * 
 * O programa escreve o LCD as letras E, D ou ambas, indicando qual 
 * ou quais os bumpers ativados.
 */
 
#include <LiquidCrystal_I2C.h>  // Biblioteca para o controlo do LCD.
 
const int BUMPER_E = 12;  // O bumper da esquerda está ligado à porta 12.
const int BUMPER_D = 0;   // O bumper da direita está ligado à porta 0.
 
// Objeto do LCD.
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD com endereço 0x27, 16 colunas e 2 linhas.
 
void setup() {
  // Inicialização do LCD
  lcd.init();
  lcd.backlight();
  lcd.noAutoscroll();
  lcd.home();
  lcd.print("Teste dos Bumpers");
 
  // Configuração das portas dos bumpers para input com pullup.
  pinMode(BUMPER_E, INPUT_PULLUP);
  pinMode(BUMPER_D, INPUT_PULLUP);
}
 
void loop() {
  lcd.setCursor(0, 1);
   
  if (digitalRead(BUMPER_E) == LOW && digitalRead(BUMPER_D) == LOW) { // Ambos os bumpers estão premidos.
    lcd.print("E e D");
  }
  else if (digitalRead(BUMPER_E) == LOW) { // O bumper da esquerda está premido.
    lcd.print("E");
  }
  else if (digitalRead(BUMPER_D) == LOW) { // O bumper da direita está premido.
    lcd.print("D");
  }
  else {
    lcd.print("     ");  // Nenhum bumper está premido.
  }
}
