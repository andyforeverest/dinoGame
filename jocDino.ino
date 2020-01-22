#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f, 16, 2);

byte bobita[] = {
  B00101,
  B01111,
  B10001,
  B10101,
  B10001,
  B11111,
  B01001,
  B11011
};

//se executa doar o data la inceputul programului
void setup() {
  pinMode(A0, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.print("Bobita game");
  Serial.begin(9600);//pentru a folosi monitorul serial
  delay(3000);
  lcd.clear();
  lcd.createChar(0, bobita);
}

int xbobita = 0;
int ybobita = 0;
//se executa la infinit
void loop() {
  lcd.setCursor(xbobita, ybobita);
  lcd.write((byte)0);
  int valoare = analogRead(A0);
  int tasta = 0;
  if (valoare < 40 && valoare > 0)
    tasta = 1;
  if (valoare < 100 && valoare > 40)
    tasta = 2;
  if (valoare < 150 && valoare > 100)
    tasta = 3;
  if (valoare < 300 && valoare > 150)
    tasta = 4;
  if (valoare < 500 && valoare > 300)
    tasta = 5;
  if (valoare > 500)
    tasta = 0;
  Serial.println(tasta);
  delay(200);

}
