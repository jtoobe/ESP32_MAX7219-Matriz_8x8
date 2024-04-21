/* tomado de un ejemplo en la web */


#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>    // Biblioteca para controlar matrices LED basadas en MAX7219/7221

// Pin DIN -> 23
// Pin CS  -> 5
// Pin CLK -> 18



int pinCS = 5; // Asigna el pin CS a este pin, DIN a MOSI y CLK a SCK 

Max72xxPanel matrix = Max72xxPanel(pinCS, 1, 1);

void setup() {
  matrix.setIntensity(4); // Establece el brillo entre 0 y 15
}

void loop() {
  // Puntos en la pantalla
  matrix.fillScreen(0);      // Esto llenará la pantalla. El parámetro controla el color.
                             // 0: está en blanco (o negro limpia la pantalla), 1: está en blanco (o encendido)
  matrix.drawPixel(0, 0, 1); // Dibuja un único píxel en la posición X 0 e Y 0. El color es 1.
                             // Esta función dibuja en un búfer, no directamente en la pantalla.
                             // Puedes hacer más dibujos en el búfer, y luego...
  matrix.drawPixel(3, 4, 1);                           
  matrix.write();            // Dibuja el búfer en la pantalla.
  
  delay(500);

  matrix.fillScreen(0);  
  matrix.drawPixel(7, 7, 1);
  matrix.write();

  delay(5000);
  
  // Líneas en la pantalla
  matrix.fillScreen(0);    
  for (int i=0;i<8;i++)             // Este bucle produce una línea en movimiento de 
  {                                 // arriba a abajo
    matrix.drawLine(0, i, 7, i, 1); // Dibuja una línea entre dos coordenadas
    matrix.write();
    delay(40);
    matrix.fillScreen(0);    
  }
  for (int i=0;i<8;i++)             // Este bucle produce una línea en movimiento de 
  {                                 // izquierda a derecha
    matrix.drawLine(i, 0, i, 7, 1);
    matrix.write();
    delay(40);
    matrix.fillScreen(0);    
  }
  for (int i=7;i>=0;i--)            // Este bucle produce una línea en movimiento de 
  {                                 // abajo a arriba
    matrix.drawLine(0, i, 7, i, 1);
    matrix.write();
    delay(40);    matrix.fillScreen(0);    
  }
  for (int i=7;i>=0;i--)            // Este bucle produce una línea en movimiento de 
  {                                 // derecha a izquierda
    matrix.drawLine(i, 0, i, 7, 1);
    matrix.write();
    delay(40);
    matrix.fillScreen(0);    
  }
  
  for (int i=0;i<8;i++)
  {                                 // Este bucle produce una línea en movimiento que
    matrix.drawLine(4, 4, i, 0, 1); // cubre el cuadrante superior
    matrix.write();
    delay(40);
    matrix.fillScreen(0);    
  }

  for (int i=0;i<8;i++)             // Este bucle produce una línea en movimiento que
  {                                 // cubre el cuadrante derecho
    matrix.drawLine(4, 4, 7, i, 1);
    matrix.write();
    delay(40);
    matrix.fillScreen(0);    
  }
  
  for (int i=7;i>=0;i--)            // Este bucle produce una línea en movimiento que
  {                                 // cubre el cuadrante inferior
    matrix.drawLine(4, 4, i, 7, 1);
    matrix.write();
    delay(40);
    matrix.fillScreen(0);    
  }
  
  for (int i=7;i>=0;i--)            // Este bucle produce una línea en movimiento que
  {                                 // cubre el cuadrante izquierdo
    matrix.drawLine(4, 4, 0, i, 1);
    matrix.write();
    delay(40);
    matrix.fillScreen(0);    
  }

  
  // Rectángulos en la pantalla
  for (int i=0;i<5;i++)                // Este bucle produce un rectángulo que
  {                                    // se contrae
  matrix.fillScreen(0);    
  matrix.drawRect(i,i,8-i*2,8-i*2,1);
  matrix.write();
  delay(40);
  }
  delay(500);

  // Círculos en la pantalla
  for (int i=0;i<4;i++)              // Este bucle produce un círculo que
  {                                  // se contrae
  matrix.fillScreen(0);    
  matrix.drawCircle(4,4,i,1);
  matrix.write();
  delay(40);
  }
  delay(500);

  // Triángulos en la pantalla
  for (int i=0;i<8;i++)                // Este bucle produce un triángulo que
  {                                    // tiene un vértice en movimiento
  matrix.fillScreen(0);      
  matrix.drawTriangle(i,i,0,7,7,0,1);
  matrix.write();
  delay(40);
  }
  for (int i=7;i>=0;i--)
  {
  matrix.fillScreen(0);      
  matrix.drawTriangle(i,i,0,7,7,0,1);
  matrix.write();
  delay(40);
  }
  delay(500);
  
  // Triángulos rellenos en la pantalla
  for (int i=0;i<8;i++)
  {
  matrix.fillScreen(0);      
  matrix.fillTriangle(i,i,0,7,7,0,1);
  matrix.write();
  delay(40);
  }
  for (int i=7;i>=0;i--)
  {
  matrix.fillScreen(0);      
  matrix.fillTriangle(i,i,0,7,7,0,1);
  matrix.write();
  delay(40);
  }
  delay(500);
  
  // Texto en la pantalla
 String my_string = "1 2 3 4 5 6 7 8 9 0";   // Este texto se mostrará, una letra a la vez
 for (int i = 0; i<my_string.length(); i++) // Recorre el contenido de la cadena
 {
  matrix.fillScreen(0);                     // Limpia la pantalla antes de mostrar el siguiente carácter
  matrix.drawChar(0,0,my_string[i],1,0,1);  // Dibuja un carácter en el búfer
  matrix.write();                           // Dibuja el búfer en la pantalla
  delay(500);
 }
 
 // Texto en movimiento
 int spacer = 1;                            // Esto hará que el texto se desplace
 int width = 5 + spacer;                    // El ancho de la fuente es de 5 píxeles
 for ( int i = 0 ; i < width * my_string.length() + width - 1 - spacer; i++ ) {

    matrix.fillScreen(0);

    int letter = i / width;
    int x = (matrix.width() - 1) - i % width;
    int y = (matrix.height() - 8) / 2; // centrar el texto verticalmente

    while ( x + width - spacer >= 0 && letter >= 0 ) {
      if ( letter < my_string.length() ) {
        matrix.drawChar(x, y, my_string[letter], 1, 0, 1);
      }

      letter--;
      x -= width;
    }

    matrix.write(); // Enviar mapa de bits a la pantalla

    delay(100);
  }
  
  /********************/
  // Brillo
  for (int i=0; i<16; i++)
  {
  matrix.setIntensity(i);
  matrix.fillScreen(i);
  matrix.write(); // Enviar mapa de bits a la pantalla
  delay(200);
  }
  /********************/
}
