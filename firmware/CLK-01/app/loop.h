#ifndef loop_h
#define loop_h

void loop()
{
  timeTick();
  if (timeJustChanged && mode == MODE_CLOCK)
  {
    flipTick();
  }
  dotTick();
  bklightBrightnessTick();
  if (currentGlitchesMode == GLITCHES_ON)
  {
    glitchTick();
  }
  buttonsTick();
  settingsTick();
  burnTick();
}

#endif
