byte minsCount = 0;
void calculateTime()
{
  dotFlag = !dotFlag;
  if (dotFlag)
  {
    dotBrightFlag = true;
    dotBrightDirection = true;
    dotBrightCounter = 0;
    secs++;
    if (secs > 59)
    {
      newTimeFlag = true; // флаг что нужно поменять время
      secs = 0;
      mins++;
      minsCount++;

      if (minsCount >= 15)
      { // каждые 15 мин
        minsCount = 0;
        DateTime now = rtc.now(); // синхронизация с RTC
        secs = now.second();
        mins = now.minute();
        hrs = now.hour();
      }

      if (mins % BURN_PERIOD == 0)
      {
        burnIndicators(); // чистим чистим!
      }
    }
    if (mins > 59)
    {
      mins = 0;
      hrs++;
      if (hrs > 23)
      {
        hrs = 0;
      }
      changeBright();
    }
    if (newTimeFlag)
    {
      setNewTime(); // обновляем массив времени
    }
  }
}