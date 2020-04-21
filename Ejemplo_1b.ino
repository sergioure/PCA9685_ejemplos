/*************************************************** 
  Fuente original: https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library
  Este es el código Arduino PAC6985 de 16 canales de servo controlador
  Prueba de servo - este codigo activara motores servo deacuerdo a la resistencia de 
  potenciometros 

  Se utiliza I2C para comunicarse, se requieren 2 pines para interfaz.
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Llamado de esta manera, utiliza la dirección por defecto 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Dependiendo de la marca de tu servo, el ancho de pulso min y max puede variar
// Quiero que sean lo más pequeños o grandes posibles sin golpear el tope.

#define SERVOMIN 125 // Esta es el valor de la longitud de pulso 'mínima' (de 4096)
#define SERVOMAX 575 // Esta es el valor de la longitud de pulso 'máxima' (de 4096)
#define SERVO_FREQ 50 // Los servos analógicos funcionan con actualizaciones de ~50 Hz

// Variable que guarda el angulo
int angle = 0;

// Pines analógicos que utilizaremos como entrada de datos 
int POT1 = A0; // Potenciometro 1 - Entrada analogica A0 - Servo 1
int POT2 = A1; // Potenciometro 2 - Entrada analogica A1 - Servo 2
int POT3 = A2; // Potenciometro 3 - Entrada analogica A2 - Servo 3
int POT4 = A3; // Potenciometro 4 - Entrada analogica A3 - Servo 4.

// No se puede utilizar A4 y A5 por que estan siendo utlizados para la 
// comunicacion I2C con la placa PCA9685

int valorPot1 = 0; // Variabre que guardara el valor del POT1
int valorPot2 = 0; // Variabre que guardara el valor del POT2
int valorPot3 = 0; // Variabre que guardara el valor del POT3
int valorPot4 = 0; // Variabre que guardara el valor del POT4

void setup() {
  Serial.begin(9600);
  Serial.println("Ejemplo 1a - Probador de servos ");

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Los servos analógicos funcionan con actualizaciones de ~50 Hz

  // No es necesario definir como INPUT las entradas analogicas
}

void loop() {
 // ***** Servo 1 - canal 0 **************
 valorPot1 = analogRead(POT1);
 Serial.print("Valor POT1: ");Serial.println(valorPot1);
 angle = map(valorPot1, 0, 1024, 0, 180);
 pwm.setPWM(0, 0, angleToPulse(angle) );
 delay(10);

  // ***** Servo 2 - canal 3 **************
 valorPot2 = analogRead(POT2);
 Serial.print("Valor POT2: ");Serial.println(valorPot2);
 angle = map(valorPot2, 0, 1024, 0, 180);
 pwm.setPWM(3, 0, angleToPulse(angle) );
 delay(10);

  // ***** Servo 3 - canal 7 **************
 valorPot3 = analogRead(POT3);
 Serial.print("Valor POT3: ");Serial.println(valorPot3);
 angle = map(valorPot3, 0, 1024, 0, 180);
 pwm.setPWM(7, 0, angleToPulse(angle) );
 delay(10);

  // ***** Servo 4 - canal 8 **************
 valorPot4 = analogRead(POT4);
 Serial.print("Valor POT4: ");Serial.println(valorPot4);
 angle = map(valorPot4, 0, 1024, 0, 180);
 pwm.setPWM(8, 0, angleToPulse(angle) );
 delay(10);
}

/********** SUB RUTINAS *******************************************************************************
 *  ***************************************************************************************************
 */
/*
 * angleToPulse(int ang)
 * Requiere el ángulo en grados y devuelve el ancho de pulso
 * también imprime el valor en el monitor serial *
 */
int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// Mapeo de angulo de 0 a 180
   Serial.print("Angulo: ");Serial.print(ang);
   Serial.print(" Pulso: ");Serial.println(pulse);
   return pulse;
    }

/********** INSTRUCCIONES ***************************************************************************
 *  *************************************************************************************************
/* Instruccion pwm.setPWM
 * Esta función establece el inicio (encendido) y el final (apagado) del segmento alto del pulso 
 * PWM en un canal específico.  Especifica el valor de 'tick' entre 0..4095 cuando la señal se 
 * enciende y cuando se apaga.  El canal indica cuál de las 16 salidas PWM debe actualizarse con 
 * los nuevos valores.
 * Primer parametro es el canal del servo
 * Segundo paramaetro es el inicio 
 * Tercer parametro es el final, por eso variamos este parametros para que el servo gire
  */

/*  ***********************************************************************************************
/* Instruccion map
 * Re-mapea un número de un rango a otro. Es decir, un valor de fromLow se mapearía a toLow, un valor 
 * de fromHigh a toHigh, 
 * Sintaxis - map (valor, fromLow, fromHigh, toLow, toHigh)
 * Parámetros - valor: el número que hay que mapear.
 *              fromLow: el límite inferior del rango actual del valor.
 *              fromHigh: el límite superior del rango actual del valor.
 *              toLow: el límite inferior del rango objetivo del valor.
 *              toHigh: el límite superior del rango objetivo del valor.
 */
