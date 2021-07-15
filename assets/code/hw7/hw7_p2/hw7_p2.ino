
// Based off of "rx_tx02  Robert Hart Mar 2019."
//  Program to use transmit-receive across space between two conductors.
//  One conductor attached to pin4, one to A0
//
//  Optionally, two resistors (1 MOhm or greater) can be placed between 5V and GND, with
//  the signal connected between them so that the steady-state voltage is 2.5 Volts.
//
//  Signal varies with electric field coupling between conductors, and can
//  be used to measure many things related to position, overlap, and intervening material
//  between the two conductors.
//



int read_high;
int read_low;
int diff;
long int sum;
int N_samples = 500;    //Number of samples to take.  Larger number slows it down, but reduces scatter.

int analog_pin = A3;
int tx_pin = A1;

void setup() {
  pinMode(A1, OUTPUT);     //Pin 4 provides the voltage step
  Serial.begin(115200);
  analogReadResolution(10);
}

void loop() {

  sum = 0;

  for (int i = 0; i < N_samples; i++) {
    digitalWrite(tx_pin, HIGH);             //Step the voltage high on conductor 1.
    read_high = analogRead(analog_pin);        //Measure response of conductor 2.
    delayMicroseconds(100);            //Delay to reach steady state.
    digitalWrite(tx_pin, LOW);              //Step the voltage to zero on conductor 1.
    read_low = analogRead(analog_pin);         //Measure response of conductor 2.
    diff = read_high - read_low;       //desired answer is the difference between high and low.
    sum += diff;                       //Sums up N_samples of these measurements.
  }
  Serial.println(sum);
  //delay(100);



}
