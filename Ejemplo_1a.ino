/*************************************************** 
  Fuente original: https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library
  Este es el código Arduino PAC6985 de 16 canales de servo controlador
  Prueba de servo - este codigo activara un servo tras otro

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

// nuestro contador de servos 
uint8_t servonum = 0;


void setup() {
  Serial.begin(9600);
  Serial.println("Ejemplo 1a - Probador de servos ");

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Los servos analógicos funcionan con actualizaciones de ~50 Hz
}

void loop() {
 // ***** Servo 1 - canal 0 **************
 for( int angle =0; angle<181; angle +=20){
    delay(100);
    pwm.setPWM(0, 0, angleToPulse(angle) );
  }
  delay(10);

// ***** Servo 2 - canal 3 **************
for( int angle =0; angle<181; angle +=20){
    delay(100);
    pwm.setPWM(3, 0, angleToPulse(angle) );
  }
  delay(10);

// ***** Servo 3 - canal 7 **************
for( int angle =0; angle<181; angle +=20){
    delay(100);
    pwm.setPWM(7, 0, angleToPulse(angle) );
  }
  delay(10);

// ***** Servo 4 - canal 8 **************
for( int angle =0; angle<181; angle +=20){
    delay(100);
    pwm.setPWM(8, 0, angleToPulse(angle) );
  }
  delay(10);

// ***** Servo 5 - canal 11 **************
for( int angle =0; angle<181; angle +=20){
    delay(100);
    pwm.setPWM(11, 0, angleToPulse(angle) );
  }
  delay(10);

  // ***** Servo 6 - canal 15 **************
for( int angle =0; angle<181; angle +=20){
    delay(100);
    pwm.setPWM(15, 0, angleToPulse(angle) );
  }
  delay(10);
}

/********** SUB RUTINAS *******************************************************************************
 *  ***************************************************************************************************
 */
/*
 * angleToPulse(int ang)
 * Obtiene el ángulo en grados y devuelve el ancho de pulso
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

/*  *************************************************************************************************
/* Instruccion map
 * Re-mapea un número de un rango a otro. Es decir, un valor de fromLow se mapearía a toLow, un valor 
 * de fromHigh a toHigh, valores intermedios a valores intermedios
 * Sintaxis - map (valor, deBajo, deAlto, aBajo, aAlto)
 * Parámetros - valor: el número que hay que mapear.
 *              deBajo: el límite inferior del rango actual del valor.
 *              desdeAltos: el límite superior del rango actual del valor.
 *              toLow: el límite inferior del rango objetivo del valor.
 *              toHigh: el límite superior del rango objetivo del valor.
 */
