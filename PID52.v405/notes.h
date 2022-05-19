#ifdef CALIBRATEthisUNITwithLibreCALC 7/10/19

=calibration of 52 for temp

=252C 2533=d14 2.20v at pin d14

=21.5c 127=d14 .22v at pin d14

=131.5C set for 125C (jack ok'ed, no mx+b for now) 1275=d14 1.16v at pid d14

#endif

#if 0

 I have all of this saved in the folder I made for the new 
design of the 52.

In order to be able to read the voltage levels for the HV and Bias 
outputs of the HV supply, we need to do the following:
1. Place a voltage divider coming out of each signal, with the following 
values:
HV: R1 - 10Mohm, R2 - 10Kohm
Bias: R1 - 10Mohm, R2 - 100Kohm
2. These signals should then be fed into opamp circuits to provide 
buffers and to invert the signal of the HV reading so the ADC board can 
handle it correctly.
  a. The HV signal should go into an inverting feedback amplifier, with 
1Kohm for Rinput and 1Kohm for Rfeedback.
  b. The Bias signal should go into a non-inverting buffer, which is an 
opamp with the signal going into the + input and the - input tied to the 
output.
3. The output of each opamp circuit should have a 100ohm resistor 
between its signal and the input of the ADC for the ESP32. The HV signal 
goes to A1 and the Bias signal goes to A2.

-Bret
#endif
