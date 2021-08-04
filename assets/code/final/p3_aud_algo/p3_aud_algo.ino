#define MICPINL A0
#define MICPINR A5

const int SAMPLEWINDOW = 1000; // Sample window width in uS
const int PEAK_THRESH = 30; // todo tweak

// can be in one of these mutually exclusive peak states:
// 0 = searching for peak
// 1 = in right peak
// 2 = in left peak
// assumes peaks never overlap
int pstate = 0;

// last 3 p2p samples
int right1ago = 0;
int right2ago = 0;
int right3ago = 0;
int left1ago = 0;
int left2ago = 0;
int left3ago = 0;

void setup() {
  Serial.begin(250000);
}


void loop() {
  int signal_max_left = 0;
  int signal_min_left = 1024;
  int signal_max_right = 0;
  int signal_min_right = 1024;
  unsigned long start_micros = micros(); // Start of sample window

  // sample p2p left and right for 1 SAMPLEWINDOW
  while (micros() - start_micros < SAMPLEWINDOW) {
    int sample_left = analogRead(MICPINL);
    int sample_right = analogRead(MICPINR);
    if (sample_left < 1024 && sample_right < 1024) { // toss out spurious readings
      if (sample_left > signal_max_left)
        signal_max_left = sample_left;  // save just the max levels
      else if (sample_left < signal_min_left)
        signal_min_left = sample_left;  // save just the min levels
      if (sample_right > signal_max_right)
        signal_max_right = sample_right;  // save just the max levels
      else if (sample_right < signal_min_right)
        signal_min_right = sample_right;  // save just the min levels
      Serial.println(sample_left);
    }
  }
  // max - min = peak-peak amplitude
  int p2p_left = signal_max_left - signal_min_left;
  int p2p_right = signal_max_right - signal_min_right;
  while(1);
  // state machine
//  if (mode == 0) {
//    // searching for a peak
//    if (p2p_right > PEAK_THRESH) {
//      // if 
//    }
//    else if (p2p_left > PEAK_THRESH) {
//
//    }
//  }
//  else if (mode == 1) {
//    // in a right peak
//
//  }
//  else {
//    // in a left peak
//
//  }

  // bookkeeping
  left3ago = left2ago;
  left2ago = left1ago;
  left1ago = p2p_left;
  right3ago = right2ago;
  right2ago = right1ago;
  right1ago = p2p_right;
  
  
  //  Serial.print("P2PL: ");
  //  Serial.println(p2p_left);
  //  Serial.print("P2PR: ");
  //  Serial.println(p2p_right);
  //  Serial.print("P2PD: ");
  //  Serial.println(p2p_left - p2p_right - 1);
//  int diff = (total_right / reps - 2) - (total_left / reps);
//  Serial.println(diff - last_sample);
//  last_sample = diff;
}
