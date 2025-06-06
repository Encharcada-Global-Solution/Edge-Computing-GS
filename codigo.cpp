#include <LiquidCrystal.h>

// Inicialização dos pinos do LCD
const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Pinos do potenciômetro, buzzer e LEDs
int potPin = A0;
int buzzerPin = 8;  // Buzzer conectado ao pino 8
int ledVerde = 9;   // LED verde
int ledAmarelo = 10; // LED amarelo
int ledVermelho = 13; // LED vermelho

void setup() {
  // Inicializa o LCD
  lcd.begin(16, 2); 
  lcd.print("SENSOR DE AGUA");
  
  // Configura os pinos do buzzer e LEDs como saída
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(potPin);  // Lê o valor do potenciômetro
  
  // Mapeia o valor do potenciômetro para porcentagem (0-100%)
  int percentage = map(sensorValue, 0, 1023, 0, 100);
  
  // Exibe a porcentagem no LCD
  lcd.setCursor(0, 1);
  lcd.print("Nivel: ");
  lcd.print(percentage);
  lcd.print("%    ");  // Espaços extras para limpar textos anteriores
  
  // Mostra o nível com os LEDs
  // Verde: até 74% (nível seguro)
  // Amarelo: 75% a 89% (atenção)
  // Vermelho: 90% a 100% (risco alto)

  if (percentage <= 74) {
    digitalWrite(ledVerde, HIGH);      // Nível tranquilo
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  } else if (percentage <= 89) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);    // Começa a encher demais
    digitalWrite(ledVermelho, LOW);
  } else {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);   // Risco de transbordo
  }

  // Controle do buzzer
  if (percentage >= 75 && percentage < 100) {
    // Faz o buzzer apitar com intervalos diminuindo (entre 75% e 99%)
    int interval = map(percentage, 75, 100, 500, 50); // Intervalo entre 500ms a 50ms
    tone(buzzerPin, 1000);  // Apita com 1000Hz
    delay(interval); // Aguarda o intervalo para o próximo apito
    noTone(buzzerPin); // Desliga o buzzer
    delay(interval); // Aguarda o mesmo intervalo antes de apitar novamente
  }
  else if (percentage == 100) {
    // Apito contínuo quando chega a 100%
    tone(buzzerPin, 1000);  // Apita com 1000Hz
  } 
  else {
    // Desliga o buzzer se o nível for menor que 75%
    noTone(buzzerPin);
  }

  delay(200);  // Delay para evitar atualizações rápidas demais no LCD
}
