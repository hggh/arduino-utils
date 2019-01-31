void ShiftOutRegister::init(short i_dataPin, short i_shiftPin, short i_storePin, short i_enablePin, short i_output_count) {
  this->dataPin = i_dataPin;
  this->shiftPin = i_shiftPin;
  this->storePin = i_storePin;
  this->enablePin = i_enablePin;
  this->output_count = i_output_count;

  pinMode(this->dataPin, OUTPUT);
  pinMode(this->shiftPin, OUTPUT);
  pinMode(this->storePin, OUTPUT);
  pinMode(this->enablePin, OUTPUT);

  digitalWrite(this->enablePin, HIGH);

  // init dynamic array with all output disabled then set OE to HIGH
  this->data = new int[this->output_count]();
  for (short i = 0; i < this->output_count; i++) {
    set_bit(i, 0);
  }
  startup();
}

void ShiftOutRegister::shift(short val) {
  digitalWrite(this->shiftPin, LOW);

  digitalWrite(this->dataPin, val);

  digitalWrite(this->shiftPin, HIGH);
}

void ShiftOutRegister::startup(void) {
  writeOut();
  digitalWrite(this->enablePin, LOW);
}

void ShiftOutRegister::set_bit(short number, short val) {
  if (number <= this->output_count) {
    this->data[number] = val;
  }
}

void ShiftOutRegister::writeOut(void) {
  digitalWrite(this->storePin, LOW);
  for (short i = this->output_count -1; i>=0; i--) {
    shift(this->data[i]);
  }
  digitalWrite(this->storePin, HIGH);
}
