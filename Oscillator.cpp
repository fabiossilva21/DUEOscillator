#include "Oscillator.h"

Oscillator::Oscillator(double frequency, double samplingFrequency) {
  this->frequency = frequency;
  this->samplingFrequency = samplingFrequency;

  resetSystem();
}

bool Oscillator::setFrequency(double frequency) {
  if (frequency > 0) this->frequency = frequency;
  else return false;

  return true;
}
bool Oscillator::setSamplingFrequency(double samplingFrequency) {
  if (samplingFrequency > 0) this->samplingFrequency = samplingFrequency;
  else return false;

  return true;
}

double Oscillator::getNext() {
  return calculateOutput(0);
}

void Oscillator::insertLastOutput (double output) {
  last_outputs[1] = last_outputs[0];
  last_outputs[0] = output;
}

double Oscillator::calculateOutput (double input) {
  double output = input - cos_w0*last_entry + 2*cos_w0*last_outputs[0] - last_outputs[1];
  insertLastOutput(output);
  last_entry = input;

  return output;
}

void Oscillator::resetSystem() {
  // Clean the system variables
  this->last_outputs[0] = 0;
  this->last_outputs[1] = 0;
  this->last_entry = 0;

  // Calculate the new oscillator data
  cos_w0 = cos(2*PI*frequency/(double)samplingFrequency);

  // Calculate the first output
  calculateOutput(1);
}
