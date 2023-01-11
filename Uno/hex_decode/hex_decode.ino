/*
By: Daniel Salinas
Contact: danielnsalinass@gmail.com
*/

void hex_decode(int *colors, String hex_data){
  int color_counter = 0;
  for(int i = 0; i < 7; i+=2){
    int first_digit = 0;
    int second_digit = 0;
    switch(hex_data.charAt(i)){
      case 'a':{
          first_digit = 10;
          break;
        }
      case 'b':{
          first_digit = 11;
          break;
        }
      case 'c':{
          first_digit = 12;
          break;
        }
      case 'd':{
          first_digit = 13;
          break;
        }
      case 'e':{
          first_digit = 14;
          break;
        }
      case 'f':{
          first_digit = 15;
          break;
        }
      default:{
          first_digit = String(hex_data.charAt(i)).toInt();
        }
    } 
    first_digit *= 16;

    switch(hex_data.charAt(i+1)){
      case 'a':{
          second_digit = 10;
          break;
        }
      case 'b':{
          second_digit = 11;
          break;
        }
      case 'c':{
          second_digit = 12;
          break;
        }
      case 'd':{
          second_digit = 13;
          break;
        }
      case 'e':{
          second_digit = 14;
          break;
        }
      case 'f':{
          second_digit = 15;
          break;
        }
      default:{
          second_digit = String(hex_data.charAt(i+1)).toInt();
        }
    }
    colors[color_counter] = first_digit + second_digit;
    color_counter++;
  }
}


void setup() {
  Serial.begin(9600);

}

void loop() {
  String hex_colors = "ffaa00";
  int colors[3];
  hex_decode(colors, hex_colors);
  Serial.print("Hex: ");
  Serial.print(hex_colors);
  Serial.print(", RGB: ");
  Serial.print(colors[0]);
  Serial.print(", ");
  Serial.print(colors[1]);
  Serial.print(", ");
  Serial.print(colors[2]);
  Serial.println(" ");
  delay(1000);
}
