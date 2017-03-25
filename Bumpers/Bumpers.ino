/**
 * Este programa testa o funcionamento dos dois bumpers do robô.
 * O cabo USB deve estar ligado e o monitor série aberto para 
 * se poderem ver as mensagens que indicam quando os bumpers são premidos.
 * 
 */

const int BUMPER_E = 12;  // O bumper da esquerda está ligado à porta 12.
const int BUMPER_D = 0;   // O bumper da direita está ligado à porta 0.
 
void setup() {
  // Configuração das portas dos bumpers para input e com pullup
  pinMode(BUMPER_E, INPUT_PULLUP);
  pinMode(BUMPER_D, INPUT_PULLUP);

  // Início da comunicação série.
  Serial.begin(9600); 
}

void loop() {
  //Devido à resistência de pullup, o valor da porta é LOW quando
  //o bumper está ativado e HIGH quando não está ativado 
  if(digitalRead(BUMPER_E) == LOW)
    Serial.println("O Bumper da esquerda está premido"); 
  if(digitalRead(BUMPER_D) == LOW)
    Serial.println("O Bumper da direita está premido"); 
}

