const int pinTrig = 4, pinEcho = 5, pinLed = 11;
const float VelocidadeSom_mporus = 0.000340;

void setup()
{
  Serial.begin(9600);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  digitalWrite(pinEcho, LOW);
  pinMode(pinLed, OUTPUT);
}

void loop()
{
 	DisparaPulsoUltrassonico();
  	float tempoEcho = pulseIn(pinEcho, HIGH);
  	float dist = CalculaDistancia(tempoEcho);
  	Serial.print("Distancia em metros: ");
  	Serial.println(dist);
  	Serial.print("Distancia em centimetros: ");
  	dist = dist * 100;
  	float aux = map(dist, 0, 300, 0, 255);
  	analogWrite(pinLed, aux);
  	Serial.println(aux);
  	Serial.println(dist);
  	delay(5000);
}

void DisparaPulsoUltrassonico(){
	digitalWrite(pinTrig, HIGH);
  	delayMicroseconds(10);
  	digitalWrite(pinTrig, LOW);
}

float CalculaDistancia(float tempo_us){
	float dist = (tempo_us * VelocidadeSom_mporus)/2;
  	return dist;
}