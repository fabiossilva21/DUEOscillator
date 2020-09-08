#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include "Arduino.h"

class Oscillator {
  public:
    Oscillator(double frequency, double samplingFrequency);

    bool setFrequency(double frequency);
    bool setSamplingFrequency(double samplingFrequency);

    double getFrequency() { return frequency; }
    double getSamplingFrequency() { return frequency; }

    double getNext();

  private:
    // Frequency data
    double frequency;
    double samplingFrequency;

    // Oscillator data
    double cos_w0;

    // Amplitude data (not working that well...)
    double amplitude = 5;

    // System Data
    double last_entry = 0;
    double last_outputs[2] = {0};

    // A way to reset the oscillator
    void resetSystem();

    void insertLastOutput (double output);
    double calculateOutput (double input);
};

#endif
