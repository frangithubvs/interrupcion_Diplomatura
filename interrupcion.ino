
volatile int contador = 0;
int n = contador;
long T0 = 0; //Variable global para tiempo


void setup() {
  // put your setup code here, to run once:
pinMode (2, INPUT);
Serial.begin(9600);
attachInterrupt (0, ServicioBoton, FALLING);
//attachInterrupt (0, ServicioBoton, RISING);//se coloca 0 porque hace referencia a la entrada dos que acepta interrupciones por hardware si es para la input 3 se coloca 1 solo estas dos entradas aceptan interrupciones en arduino uno
//attachInterrupt (digitalPinToInterrupt(2) ,ServicioBoton, RISING) con rising detecta el flanco positivo
}

void loop() {
  // put your main code here, to run repeatedly:
if (n != contador)
{ Serial.print ("!!contador=");
  Serial.println (contador);
n = contador;
  
}
}
void ServicioBoton()
{ if (millis()> T0+ 250)

  contador++;
  T0=millis ();
}
