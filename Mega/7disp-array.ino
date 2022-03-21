//7 Segment Display Demo on Arduino Mega
//Daniel Salinas @ 21/03/2022

const int DISPPINS[] = {26, 28, 30, 32, 34, 22, 24};

const int DNULL[]  = {0,0,0,0,0,0,0};
const int D1[] = {1,1,0,0,0,0,0};
const int D2[] = {1,1,0,0,0,1,1};
const int D3[] = {1,1,1,0,1,0,1};
const int D4[] = {1,1,1,1,1,1,1};
const int D5[] = {1,1,0,0,0,0,0};
const int D6[] = {0,1,1,1,1,1,1};

void printNum(int num[]){
    for(int i =0; i<7;i++){
        digitalWrite(DISPPINS[i], num[i]);
      }
  }

void setup() {
  Serial.begin(9600);
  for(int i=0;i<7;i++){
      pinMode(i, OUTPUT);
    }
}

void loop() {
  printNum(D1);
  delay(500);
  printNum(DNULL);
  delay(500);

  printNum(D2);
  delay(500);
  printNum(DNULL);
  delay(500);

  printNum(D3);
  delay(500);
  printNum(DNULL);
  delay(500);

  printNum(D4);
  delay(500);
  printNum(DNULL);
  delay(500);

  printNum(D5);
  delay(500);
  printNum(DNULL);
  delay(500);

  printNum(D6);
  delay(500);
  printNum(DNULL);
  delay(500);
  
}
